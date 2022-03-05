#include "avl3.hpp"


void nr_teams(ifstream&,int *);
listt* generate_list(ifstream&,int);
q* generate_q(listt *);
//stiva* generate_winners_bracket(q*,int*);
q* regenerate_q(stiva*);
void print_winners(stiva*,ofstream&);
BST* top8(stiva*);
AVLTree* create_AVL(stiva* s);
void print_avl(AVLNode*,ofstream&);
void Inorder_to_stiva(BST*,stiva*);
//AVLnode* level_2(stiva* s);
//AVL create_avl(stiva*);

//MAIN PENTRU CODEBLOCKS//////////////////////////////////////////////////////////////////////////////////////////////////////////MAIN PT CODEBLOCKS

/*
int main(){

    ifstream filein("d.in");
    //ifstream checkerin(checkerFile);
    ofstream fileout("rezultatavl.txt");

    int cerinte[5];
    for(int i=0;i<5;i++){
        cerinte[i]=1;
    }

    listt *p;
    q *que;

    int n=0;

    if(!filein){
        cout<<endl<<"EROARE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }
    nr_teams(filein,&n);
    p=generate_list(filein,n);

    int nr_cerinte=0;
    for(int i=0;i<5;i++){
        if(cerinte[i]==1){
            nr_cerinte=nr_cerinte+cerinte[i];
        }
    }
    if(nr_cerinte==1){
        print_list(p,fileout);
    }

    if(cerinte[1]==1){

        remove_element(&p,&n);
        print_list(p,fileout);

        if(cerinte[2]==1){

            fileout<<endl;

            stiva* winners_bracket;
            stiva* loosers_bracket;

            int n_copy=n;
            int n_putere_2=0;
            while(n_copy>1){
                n_putere_2++;
                n_copy=n_copy/2;
            }
            //n_copy=n;

            int i=1;
            BST* arbor;
            BST b;
            //AVLnode* lvl2;
            //AVL john;

            AVLTree *avl;
            stiva* s_avl = NULL;

            while(n>1){

                if(n==8){

                    arbor=top8(winners_bracket);

                    //fileout<<"--- Here is the winner bracket before adding to AVL: ---\n";
                    //print_winners(winners_bracket, fileout);
                    //fileout<<"--------------";
                    //lvl2=level_2(winners_bracket);
                    //AVLinorder(lvl2,fileout);
                    //john=create_avl(winners_bracket);

                    cout<<endl<<"NU CRAPA"<<endl;


                }

                fileout<<"--- ROUND NO:"<<i<<endl;//<<" Numar Echipe: "<<n<<endl;

                if(i==1){

                    que=generate_q(p);
                    delete_list(&p);
                    print_queue(que,fileout);
                    winners_bracket=generate_stiva(que,&n);
                    loosers_bracket=generate_stiva_loosers(que);
                    fileout<<endl<<"WINNERS OF ROUND NO:"<<i<<endl;
                    print_winners(winners_bracket,fileout);

                    delete_q(que);


                }
                else{

                    que=regenerate_q(winners_bracket);
                    delete_stiva(&winners_bracket);
                    print_queue(que,fileout);
                    winners_bracket=generate_stiva(que,&n);
                    loosers_bracket=generate_stiva_loosers(que);
                    fileout<<endl<<"WINNERS OF ROUND NO:"<<i<<endl;
                    print_winners(winners_bracket,fileout);
                    delete_q(que);

                }

                if(i==n_putere_2){
                    break;
                }
                else{
                    fileout<<endl;
                }

                i++;

            }

            if(cerinte[3]==1){
                b.Inorder_to_stiva(arbor,&s_avl);
                fileout<<endl<<"TOP 8 TEAMS:"<<endl;
                b.Inorder(arbor,fileout);
                //free(arbor);


                stiva *s_avl_reversed = NULL;
                while(s_avl){
                    push(&s_avl_reversed, s_avl->getWinnerTeam());
                    stiva *aux = s_avl->getNext();
                    free(s_avl);
                    s_avl = aux;
                }
                avl=create_AVL(s_avl_reversed);

            }

            if(cerinte[4]==1){
                //fileout<<endl<<"THE LEVEL 2 TEAMS ARE:"<<endl;
                //AVLinorder(lvl2,fileout);
                //fileout<<"LEVEL 1:"<<endl;
                //AVLout(lvl2,fileout,1);
                //fileout<<endl;
                //fileout<<"LEVEL 2:"<<endl;
                //AVLout(lvl2,fileout,2);
                //fileout<<endl;
                //fileout<<"LEVEL 3:"<<endl;
                //AVLout(lvl2,fileout,3);
                //fileout<<endl;
                //fileout<<"LEVEL 4:"<<endl;
                //AVLout(lvl2,fileout,4);
                //fileout<<endl;
                //fileout<<endl<<"AVL PE LEVELE E:"<<endl;
                //john.levelorder_newline(fileout);
                //cout<<endl<<"NU CRAPA"<<endl;

                fileout<<endl<<"THE LEVEL 2 TEAMS ARE:"<<endl;
                if(avl->getRoot() && (avl->getNil() != avl->getRoot()))
                    print_avl_level(avl,avl->getRoot()->getLeft(),fileout, 0);
                //print_avl_level(avl,avl->getRoot(),fileout,0);
            }

            //fileout<<endl<<"TOP 8 TEAMS:"<<endl;
            //b.Inorder(arbor,fileout);


        }
    }
    filein.close();
    return 0;


}
*/

//MAIN PENTRU CHECKER////////////////////////////////////////////////////////////////////////////////////MAIN PENTRU CHECKER



int main(int argc, char **argv){

    string infile = argv[2];
    string outfile = argv[3];
    string checkerFile = argv[1];

    ifstream filein(infile);
    ifstream checkerin(checkerFile);
    ofstream fileout(outfile);


    int cerinte[5];
    for(int i=0;i<5;i++){
        checkerin>>cerinte[i];
    }

    listt *p;
    q *que;

    int n=0;

    if(!filein){
        cout<<endl<<"EROARE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }
    nr_teams(filein,&n);
    p=generate_list(filein,n);

    int nr_cerinte=0;
    for(int i=0;i<5;i++){
        if(cerinte[i]==1){
            nr_cerinte=nr_cerinte+cerinte[i];
        }
    }
    if(nr_cerinte==1){
        print_list(p,fileout);
    }

    if(cerinte[1]==1){

        remove_element(&p,&n);
        print_list(p,fileout);

        if(cerinte[2]==1){

            fileout<<endl;

            stiva* winners_bracket;
            stiva* loosers_bracket;

            int n_copy=n;
            int n_putere_2=0;
            while(n_copy>1){
                n_putere_2++;
                n_copy=n_copy/2;
            }
            //n_copy=n;

            int i=1;
            BST* arbor;
            BST b;

            //AVLnode* lvl2;
            //AVL john;

            AVLTree *avl;
            stiva* s_avl = NULL;

            while(n>1){

                if(n==8){

                    arbor=top8(winners_bracket);


                    //lvl2=level_2(winners_bracket);
                    //AVLinorder(lvl2,fileout);
                    //john=create_avl(winners_bracket);

                }

                fileout<<"--- ROUND NO:"<<i<<endl;//<<" Numar Echipe: "<<n<<endl;

                if(i==1){

                    que=generate_q(p);
                    delete_list(&p);
                    print_queue(que,fileout);
                    winners_bracket=generate_stiva(que,&n);
                    loosers_bracket=generate_stiva_loosers(que);
                    fileout<<endl<<"WINNERS OF ROUND NO:"<<i<<endl;
                    print_winners(winners_bracket,fileout);

                    delete_q(que);


                }
                else{

                    que=regenerate_q(winners_bracket);
                    delete_stiva(&winners_bracket);
                    delete_stiva(&loosers_bracket);
                    print_queue(que,fileout);
                    winners_bracket=generate_stiva(que,&n);
                    loosers_bracket=generate_stiva_loosers(que);
                    fileout<<endl<<"WINNERS OF ROUND NO:"<<i<<endl;
                    print_winners(winners_bracket,fileout);
                    delete_q(que);

                }

                if(i==n_putere_2){
                    break;
                }
                else{
                    fileout<<endl;
                }

                i++;

            }

            if(cerinte[3]==1){

                b.Inorder_to_stiva(arbor,&s_avl);

                fileout<<endl<<"TOP 8 TEAMS:"<<endl;
                b.Inorder(arbor,fileout);
                //free(arbor);

                stiva *s_avl_reversed = NULL;
                while(s_avl){
                    push(&s_avl_reversed, s_avl->getWinnerTeam());
                    stiva *aux = s_avl->getNext();
                    free(s_avl);
                    s_avl = aux;
                }
                avl=create_AVL(s_avl_reversed);

                destroyBST(arbor);
                delete_stiva(&s_avl_reversed);
            }

            if(cerinte[4]==1){

                fileout<<endl<<"THE LEVEL 2 TEAMS ARE: "<<endl;
                if(avl->getRoot() && (avl->getNil() != avl->getRoot())){
                    print_avl_level(avl,avl->getRoot()->getLeft(),fileout, 0);
                }

                avlDestroyTree(avl);
            }

            delete_stiva(&winners_bracket);
            delete_stiva(&loosers_bracket);

        }

    }

    filein.close();
    fileout.close();

    return 0;


}
