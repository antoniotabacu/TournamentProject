#include "bst.hpp"

BST ::BST(){

    //data=new team;

    left=NULL;
    right=NULL;

}

// Parameterized Constructor definition.
BST ::BST(team value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST* BST ::insert_node(BST* root, team value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if (value.getTeamPoints() < root->data.getTeamPoints())
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = insert_node(root->right, value);
    }
    if (value.getTeamPoints() > root->data.getTeamPoints())
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = insert_node(root->left, value);
    }
    if (value.getTeamPoints() == root->data.getTeamPoints()){

        if(value.get_team_name()<root->data.get_team_name()){
            root->right = insert_node(root->right, value);
        }
        else{
            root->left = insert_node(root->left, value);
        }
    }

    // Return 'root' node, after insertion.
    return root;
}

void BST ::Inorder(BST* root,ofstream& fileout){

    //ofstream refileout("r.out",ios::app);
    //cout<<"lol";
    if (!root) {
        return;
    }
    Inorder(root->left,fileout);
    fileout<< root->data.get_team_name();
    for(int j=0;j<34-(root->data.get_team_name().length());j++){
        fileout<<" ";
    }
    fileout<<"-  ";
    fileout<<setprecision (2)<<fixed<<root->data.getTeamPoints()<<endl;
    //refileout<<endl;
    Inorder(root->right,fileout);
}

void BST::Inorder_to_stiva(BST* root,stiva** s){

    if (!root) {
        return;
    }
    //Inorder_to_stiva(root->left,s);

    Inorder_to_stiva(root->left,s);
    push(s,root->data);
    Inorder_to_stiva(root->right,s);

}

BST* top8(stiva* s){

    BST arbor8, *root=NULL;

    int i=1;
    while(s!=NULL){

        if(i==1){
            root=arbor8.insert_node(root,s->getWinnerTeam());
        }
        else{
            arbor8.insert_node(root,s->getWinnerTeam());
        }

        s=s->getNext();

        i++;
    }

    return root;

}

void destroyBST(BST* root){

    if(!root){
        return;
    }
    destroyBST(root->left);
    free(root);
    destroyBST(root->right);

}


