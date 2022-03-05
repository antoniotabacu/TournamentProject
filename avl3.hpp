#include "bst.hpp"

class AVLNode{

    team elem;
    int height;
    AVLNode *l;
    AVLNode *r;
    AVLNode *p;

    friend class AVLTree;

public:

    team getElem();
    int getHeight();
    AVLNode* getLeft();
    AVLNode* getRight();
    AVLNode* getParent();

    void setElem(team);
    void setHeight(int);
    void setLeft(AVLNode*);
    void setRight(AVLNode*);
    void setParent(AVLNode*);

};

class AVLTree{

    long tree_size;
    AVLNode* root;
	AVLNode* nil;


public:

    AVLNode* getRoot();
    AVLNode* getNil();

    //friend int comp(team,team);
    //friend AVLTree* AVLCreateTree(int (*comp) (Item1,Item1));
    friend AVLTree* AVLCreateTree2();
    friend int avlIsEmpty(AVLTree* tree);
    friend AVLNode* avlNewNode(AVLTree* tree);
    friend void avlRightRotate(AVLTree *tree, AVLNode *x);
    friend void avlLeftRotate(AVLTree *tree, AVLNode *x);
    friend int avlGetBalance(AVLNode *x);
    friend int max(int a, int b);
    friend AVLNode * avlMinimum(AVLTree* tree, AVLNode* x);
    friend AVLNode* avlMaximum(AVLTree* tree, AVLNode* x);
    friend void avlFixUp(AVLTree *tree, AVLNode *node);
    friend void avlInsert(struct AVLTree* tree, team elem);
    friend void avlDeleteNode(AVLTree *tree, AVLNode* node);
    friend void avlDestroyTreeHelper(AVLTree* tree, AVLNode* x);
    friend void avlDestroyTree(AVLTree* tree);
    friend AVLTree* create_AVL(stiva* s);
    friend void print_avl(AVLTree*,AVLNode*,ofstream&);
    friend void print_avl_level(AVLTree*,AVLNode*,ofstream&,int);
    int comp(team a,team b);
};
