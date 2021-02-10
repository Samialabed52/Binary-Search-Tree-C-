#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(int val)
{
    if(root == NULL)
    {
        pointing = new Node(val, NULL, NULL);
        root = pointing;
    }
    
    if(val < pointing->value)
    {
        if(pointing->left == NULL)
        {
            pointing->left = new Node(val, NULL, NULL);
            pointing = root;
        }
        else
        {
            pointing = pointing->left;
            insert(val);
        }
    }
    
    else if(val > pointing->value)
    {
        if(pointing->right == NULL)
        {
            pointing->right = new Node(val, NULL, NULL);
            pointing = root;
        }
        else
        {
            pointing = pointing->right;
            insert(val);
        }
    }
}

void BinarySearchTree::print_tree(Node *p, Node *s)
{
    if(root == NULL)
        std::cout << "Cannot print - list is empty" << std::endl;
    else
    {
        if(p == NULL)
        {
            p = root;
            s = p;    
            std::cout << "\nBinary Search Tree: " << std::endl;
        }
        if(s == NULL)
            return;
        print_tree(p, s->left);
        std::cout << s->value << std::endl;
        print_tree(p, s->right);
    }
}

void BinarySearchTree::delete_node(int val, Node *p, Node *s)
{
    if(root == NULL)
    {
        std::cout << "\nCannot perform delete - The tree is empty" << std::endl;
    }
    else if(root != NULL)
    {
        if(p == NULL)
        {
            p = root;
            s = p;
        }        
        
        if(val != s->value)
        {
            if(val < s->value)
            {
                if(s->left == NULL)
                    return;
                else
                {
                    pointing = s;
                    delete_node(val, p, s->left);
                }
            }
            else if(val > s->value)
            {
                if(s->right == NULL)
                    return;
                else
                {
                    pointing = s;
                    delete_node(val, p, s->right);
                }
            }
        }
        else if(val == s->value)
        {
            if(val == root->value)
            {
                pointing = root->left;
            if(pointing->left == NULL && pointing->right ==NULL)
            {
                root->value = pointing->value;
                root->left = NULL;
            }
            else
            {
                while(pointing->right != NULL)
                    pointing = pointing->right;
                p = root->left;
                while(p->right != pointing)
                    p = p->right;
                if(pointing->left == NULL)
                {
                    root->value = pointing->value;
                    p->right = NULL;
                }
                else
                {
                    root->value = pointing->value;
                    p->right = pointing->left;
                    pointing->left = NULL;
                }
            }
                pointing = root;
                std::cout << "\nRoot was deleted" << std::endl;
            }
            
            else if(pointing->value < s->value) //value on right of its parent
            {
                if(s->left == NULL && s->right == NULL)
                {
                    pointing->right = NULL;
                }
                else if(s->left == NULL)
                {
                    pointing->right = s->right;
                    s->right = NULL;
                }
                else if(s->right == NULL)
                {
                    pointing->right = s->left;
                    s->left = NULL;
                }
                else
                {
                    pointing->right = s->left;
                    p = s->right;
                    s = s->left;
                    while(s->right != NULL)
                        s = s->right;
                    s->right = p;
                }
                pointing = root;
                std::cout << "\nThe value " << val << " was deleted" << std::endl;
            }
            else if(pointing->value > s->value) //left of parent
            {
                if(s->left == NULL && s->right == NULL)
                {
                    pointing->left = NULL;
                }
                if(s->right == NULL)
                {
                    pointing->left = s->left;
                    s->left = NULL;
                }
                if(s->left == NULL)
                {
                    pointing->left = s->right;
                    s->right = NULL;
                }
                else
                {
                    pointing->left = s->right;
                    p = s->left;
                    s = s->right;
                    while(s->left != NULL)
                        s = s->left;
                    s->left = p;
                }
                pointing = root;
                std::cout << "\nThe value " << val << " was deleted" << std::endl;
            }
        }
    }
}

void BinarySearchTree::search(int val)
{
    if(root == NULL)
    {
        std::cout << "\nCannot perform search - The tree is empty" << std::endl;
    }
    else
    {
        if(val == root->value)
            std::cout << "\nThe value " << val << " is the root of the tree!" << std::endl;
        else if(val > pointing->value)
        {
            if(pointing->right == NULL)
            {
                std::cout << "\nThe value " << val << " is not in the tree!" << std::endl;
                pointing = root;
            }
            else
            {
                pointing = pointing->right;
                search(val);
            }
        }
        else if(val < pointing->value)
        {
            if(pointing->left == NULL)
            {
                std::cout << "\nThe value " << val << " is not in the tree!" << std::endl;
                pointing = root;
            }
            else
            {
                pointing = pointing->left;
                search(val);
            }         
        }
        else if(val == pointing->value)
        {
            std::cout << "\nThe value " << val << " was found!" << std::endl;
            pointing = root;
        }
    }
}
