#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_
#include "Node.h"
#include <string>

class BinarySearchTree
{
private:
    Node *root;
    Node *pointing;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    void insert(int);
    void print_tree(Node *, Node *);
    void delete_node(int, Node *, Node *);
    void search(int);
};

#endif // _BINARYSEARCHTREE_H_
