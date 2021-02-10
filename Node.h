#ifndef _NODE_H_
#define _NODE_H_

class Node
{
    friend class BinarySearchTree;
private:
    int value;
    Node *left;
    Node *right;
    
public:
    Node(int val, Node *lt, Node *rt);
};

#endif // _NODE_H_
