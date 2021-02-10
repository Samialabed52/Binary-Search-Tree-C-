#include <iostream>
#include "BinarySearchTree.h"

int main ()
{
    Node *p = NULL;
    Node *s = NULL;
    
    BinarySearchTree tree1;
    tree1.insert(2);
    tree1.insert(1);
    tree1.insert(4);
    tree1.insert(5);
    tree1.insert(9);
    tree1.insert(3);
    tree1.insert(6);
    tree1.insert(7);
    tree1.insert(10);
    tree1.insert(12);
    tree1.insert(11);
    tree1.print_tree(p, s);
    tree1.delete_node(4, p, s);
    tree1.delete_node(9, p, s);
    tree1.print_tree(p, s);
    tree1.search(12);
    tree1.search(4);
}