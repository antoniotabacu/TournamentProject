#include "avl3.hpp"

team AVLNode::getElem(){

    return elem;

}

int AVLNode::getHeight(){

    return height;

}

AVLNode* AVLNode::getLeft(){

    return l;

}

AVLNode* AVLNode::getRight(){

    return r;

}

AVLNode* AVLNode::getParent(){

    return p;

}

void AVLNode::setElem(team t){

    elem=t;

}

void AVLNode::setHeight(int t){

    height=t;

}

void AVLNode::setLeft(AVLNode* t){

    l=t;

}

void AVLNode::setRight(AVLNode* t){

    r=t;

}

void AVLNode::setParent(AVLNode* t){

    p=t;

}

int AVLTree::comp(team a, team b){

    if(a.getTeamPoints()>b.getTeamPoints()){
        return 1;
    }
    if(a.getTeamPoints()<b.getTeamPoints()){
        return -1;
    }

    if(a.getTeamPoints()==b.getTeamPoints()){
        if(a.get_team_name()>b.get_team_name()){
            return 1;
        }
        if(a.get_team_name()<=b.get_team_name()){
            return -1;
        }
    }

    return 0;

}

/*AVLTree* AVLCreateTree(int (*comp)(team1,team2)){

    AVLTree* newTree=new AVLTree;
    newTree->comp=comp;
    newTree->nil=new AVLNode;
    newTree->nil->p = newTree->nil->l = newTree->nil->r = newTree->nil;

    newTree->nil->height = 0;
    newTree->root=new AVLNode;
    newTree->root->p = newTree->root->l = newTree->root->r = newTree->nil;
    newTree->root->height = 0;
	newTree->size = 0;

	return newTree;

}*/

AVLTree* AVLCreateTree2(){

    AVLTree* newTree=new AVLTree;
    newTree->nil=new AVLNode;

    newTree->nil->setRight(newTree->nil);
    newTree->nil->setLeft(newTree->nil->getRight());
    newTree->nil->setParent(newTree->nil->getLeft());

    newTree->nil->setHeight(0);

    newTree->root=new AVLNode;

    newTree->root->setRight(newTree->nil);
    newTree->root->setLeft(newTree->root->getRight());
    newTree->root->setParent(newTree->root->getLeft());

    newTree->root->setHeight(0);
	newTree->tree_size = 0;

	return newTree;

}

int avlIsEmpty(AVLTree* tree){

    return(tree->root->getLeft()==tree->nil);

}

AVLNode* avlNewNode(AVLTree* tree){

    AVLNode* newNode=new AVLNode;

    newNode->setLeft(tree->nil);
    newNode->setRight(newNode->getLeft());
    newNode->setParent(newNode->getRight());

	newNode->setHeight(1);

	return newNode;

}

void avlRightRotate(AVLTree *tree, AVLNode *x){

    if(x == x->getParent()->getLeft())
		x->getParent()->setLeft(x->getLeft());
	else
		//x->p->r = x->l;
		x->getParent()->setRight(x->getLeft());

	//x->l->p = x->p;
	x->getLeft()->setParent(x->getParent());

	//x->p = x->l;
	x->setParent(x->getLeft());

	//x->l = x->p->r;
	x->setLeft(x->getParent()->getRight());

	//x->p->r = x;
	x->getParent()->setRight(x);

}

void avlLeftRotate(AVLTree *tree, AVLNode *x){
	if(x == x->getParent()->getLeft())
		x->getParent()->setLeft(x->getRight());
	else
		//x->p->r = x->r;
		x->getParent()->setRight(x->getRight());

	/*x->r->p = x->p;
	x->p = x->r;
	x->r = x->p->l;
	x->p->l = x;*/

	x->getRight()->setParent(x->getParent());
	x->setParent(x->getRight());
	x->setRight(x->getParent()->getLeft());
	x->getParent()->setLeft(x);
}

int avlGetBalance(AVLNode *x){
	if (x == NULL)
		return 0;
	return x->getRight()->getHeight() - x->getLeft()->getHeight();
}

AVLNode * avlMinimum(AVLTree* tree, AVLNode* x){
	while (x->getLeft() != tree->nil)
		x = x->getLeft();
	return x;
}

AVLNode* avlMaximum(AVLTree* tree, AVLNode* x){
	while(x->getRight() != tree->nil){
		x = x->getRight();
	}
	return x;
}

void avlFixUp(AVLTree *tree, AVLNode *node){
	node = node->getParent();
	int nr = 0;
	while(node != tree->root){
		++ nr;
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight()) + 1);
		int balance = avlGetBalance(node);
		if(balance == 2){
			int balanceSon = avlGetBalance(node->getRight());
			if(balanceSon >= 0){
				avlLeftRotate(tree, node);
			}
			else{
				avlRightRotate(tree, node->getRight());
				avlLeftRotate(tree, node);
			}
		}
		if(balance == -2){
			int balanceSon = avlGetBalance(node->getLeft());
			if(balanceSon <= 0){
				avlRightRotate(tree, node);
			}
			else{
				avlLeftRotate(tree, node->getLeft());
				avlRightRotate(tree, node);
			}
		}
		node->setHeight(max(node->getLeft()->getHeight(), node->getRight()->getHeight()) + 1);
		node = node->getParent();
	}

}

void avlInsert(AVLTree* tree, team elem){
	AVLNode *newNode = avlNewNode(tree);
	newNode->setElem(elem);
	if(tree->tree_size == 0){
		tree->root->setLeft(newNode);
		newNode->setParent(tree->root);
		newNode->setHeight(0);
		tree->tree_size = 1;
		return;
	}
	AVLNode *crtNode = tree->root->getLeft();
	while(1){
		if(tree->comp(elem, crtNode->getElem()) < 0){
			if(crtNode->getLeft() == tree->nil){
				crtNode->setLeft(newNode);
				newNode->setParent(crtNode);
				break;
			}
			crtNode = crtNode->getLeft();
		}
		else{
			if(crtNode->getRight() == tree->nil){
				crtNode->setRight(newNode);
				newNode->setParent(crtNode);
				break;
			}
			crtNode = crtNode->getRight();
		}
	}
	avlFixUp(tree, newNode);
	tree->tree_size ++;

}

void destroyElem(team elem){


    elem.deletePlayers();

}

void avlDeleteNode(AVLTree *tree, AVLNode* node){

    //cout<<endl<<"NU CRAPA"<<endl;
	destroyElem(node->getElem());
	free(node);
}


void avlDestroyTreeHelper(AVLTree* tree, AVLNode* x) {
	if (x != tree->nil) {
		avlDestroyTreeHelper(tree,x->getLeft());
		avlDestroyTreeHelper(tree,x->getRight());
		avlDeleteNode(tree,x);
	}
}

void avlDestroyTree(AVLTree* tree){
    if(!tree->root){
        return;
    }
	avlDestroyTreeHelper(tree, tree->root->getLeft());
	free(tree->root);
	free(tree->nil);
	free(tree);
}

AVLTree* create_AVL(stiva* s){

    AVLTree* t;
    t=AVLCreateTree2();
    while(s!=NULL){

        //cout<<endl<<"NU CRAPA"<<endl;

        avlInsert(t,s->getWinnerTeam());
        s=s->getNext();
    }

    return t;

}

void print_avl(AVLTree *avl, AVLNode *crt,ofstream& fileout){
    AVLNode *nil = avl->getNil();

    if (crt && crt != nil){

        print_avl(avl,crt->getRight(),fileout);
        //printf("%d ",root->val);
        //if(root->height==1){
            fileout<<crt->getElem().get_team_name()<<endl;
        //}
        print_avl(avl,crt->getLeft(),fileout);

    }

}

void print_avl_level(AVLTree *avl, AVLNode *crt, ofstream& fileout, int level){

    AVLNode *nil = avl->getNil();

    if (crt && crt != nil){
        if(level == 2){
            fileout<<crt->getElem().get_team_name()<<endl;
            return;
        }

        print_avl_level(avl, crt->getRight(),fileout, level + 1);
        print_avl_level(avl, crt->getLeft(),fileout, level + 1);
    }
}

AVLNode* AVLTree::getRoot(){

    return root;

}

AVLNode* AVLTree::getNil(){

    return nil;

}
