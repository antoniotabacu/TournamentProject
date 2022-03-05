#include "queue.hpp"

class BST{

    team data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(team);

    // Insert function.
    BST* insert_node(BST*, team);

    void Inorder(BST*,ofstream&);
    void Inorder_to_stiva(BST*,stiva**);

    friend BST* top8(stiva*);

    friend void print_top(BST* );

    friend void destroyBST(BST*);

};
