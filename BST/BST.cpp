//
//  BST.cpp
//  BST
//
//  Created by Robert Schwartz on 3/25/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include "BST.hpp"

//insert a node containing data into BST
template<typename T>
void BST<T>::insert(const T data)
{
    Node<T> *r = this->root;
    Node<T> *prev;
    
    //if tree is empty
    if(root == 0)
    {
        root = new Node<T>(data);
    }
    
    //find position to insert node
    while (r != 0)
    {
        prev = r;
        if(data < r->data)
        {
            r = r->left;
            if(r == NULL)
            {
                prev->left = new Node<T>(data);
            }
        }
        else
        {
            r = r->right;
            if(r == NULL)
            {
                prev->right = new Node<T>(data);
            }
        }
    }
}

//recursive function to print out BST inorder
template<typename T>
void BST<T>::inorder(Node<T> *node)
{
    if(node == NULL)
    {
        return;
    }
    inorder(node->left);
    std::cout << node->data << " \n";
    inorder(node->right);
}

//function for BST to call inorder without passing individual nodes as parameters
template<class T>
void BST<T>::printInorder(){ inorder(this->root); }

//recursive function to print out BST preorder
template<class T>
void BST<T>::preorder(Node<T> *node)
{
    if(node == NULL)
    {
        return;
    }
    std::cout << node->data << " \n";
    preorder(node->left);
    preorder(node->right);
}

//function for BST to call preorder without passing individual nodes as parameters
template<class T>
void BST<T>::printPreorder(){ preorder(this->root); }

//recursive function to print out BST postorder
template<class T>
void BST<T>::postorder(Node<T> *node)
{
    if(node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " \n";
}

//function for a BST to call postorder without passing individual nodes as parameters
template<class T>
void BST<T>::printPostorder(){ postorder(this->root); }

//search tree for node containing a value
template<class T>
bool BST<T>::search(const T& data)
{
    Node<T> *tmp = this->root;
    if(root == 0)
    {
        std::cout << "The tree is empty\n";
        return 0;
    }
    
    while(true)
    {
        if(tmp == nullptr)
        {
            std::cout << data << " is not in the tree\n";
            return 0;
        }
        if(data == tmp->data)
        {
            std::cout << data << " is in the tree.\n";
            return 1;
        }
        else if(data < tmp->data)
        {
            tmp = tmp->left;
        }
        else if(data > tmp->data)
        {
            tmp = tmp->right;
        }
    }
}

//remove node in tree
template<class T>
bool BST<T>::remove(const T& data)
{
    //if tree is empty
    if(root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        Node<T> *auxRoot;
        this->root = auxRoot->left;
        Node<T> *removedNode = root->remove(data, auxRoot);
        root = auxRoot->left;
        if(removedNode != NULL)
        {
            delete removedNode;
            return true;
        }
        else return false;
    }
    else
    {
        Node<T> *removedNode = root->remove(data, NULL);
        if(removedNode != NULL)
        {
            delete removedNode;
            return true;
        }
        else return false;
    }
}
