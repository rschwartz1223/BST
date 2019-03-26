//
//  BST.hpp
//  BST
//  Custom self-balancing Binary Search Tree implementation.
//
//  Created by Robert Schwartz on 3/25/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <iostream>

template<class T>
class Node
{
public:
    Node(){ left = right = 0; }
    Node(const T& _data) : data(_data){}
    Node(const T& _data, Node<T> *_left, Node<T> *_right) : data(_data), left(_left), right(_right){}
    Node<T>* remove(const T& data, Node<T> *node);
    T minValue();
    T data;
    Node<T> *left, *right;
};

template<class T>
class myBST {
public:
    myBST() {root = 0;}
    void insert(const T& data);
    void inorder(Node<T> *node);
    void preorder(Node<T> *node);
    void postorder(Node<T> *node);
    void printInorder();
    void printPreorder();
    void printPostorder();
    bool search(const T& data);
    bool remove(const T& value);
    Node<T> *root;
};

// function to insert a node containing data into BST
template<class T>
void myBST<T>::insert(const T& data) {
    Node<T> *r = root, *prev = 0;
    // if tree is empty
    if (root == 0)
        root = new Node<T>(data);
    
    /* find position to insert node assuming
     tree is not empty */
    while (r != 0) {
        prev = r;
        if (data < r->data){
            r = r->left;
            if(r == NULL)
                prev->left = new Node<T>(data);
        }
        else {
            r = r->right;
            if (r == NULL)
                prev->right = new Node<T>(data);
        }
    }
}

// recursive function to print out BST inorder
template<class T>
void myBST<T>::inorder(Node<T> *node) {
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " \n";
    inorder(node->right);
}
/* function for a BST to call inorder without passing
 individual nodes as parameters */
template<class T>
void myBST<T>::printInorder() {
    inorder(this->root);
}

// recursive function to print out BST preorder
template<class T>
void myBST<T>::preorder(Node<T> *node) {
    if (node == NULL)
        return;
    cout << node->data << " \n";
    preorder(node->left);
    preorder(node->right);
}
/* function for a BST to call preorder without passing
 individual nodes as parameters */
template<class T>
void myBST<T>::printPreorder() {
    preorder(this->root);
}

// recursive function to print out BST postorder
template<class T>
void myBST<T>::postorder(Node<T> *node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " \n";
}
/* function for a BST to call postorder without passing
 individual nodes as parameters */
template<class T>
void myBST<T>::printPostorder() {
    postorder(this->root);
}

// search tree for node containing a value
template<class T>
bool myBST<T>::search(const T& data) {
    Node<T> *tmp = this->root;
    if (root == 0) {
        cout << "The tree is empty\n";
        return 0;
    }
    
    while (true) {
        if (data == tmp->data) {
            cout << data << " is in the tree.\n";
            return 1;
        }
        else if (data < tmp->data)
            tmp = tmp->left;
        else if(data > tmp->data)
            tmp = tmp->right;
        if (tmp == nullptr) {
            cout << data << " is not in the tree\n";
            return 0;
        }
    }
}

// remove node containing data
template<class T>
bool myBST<T>::remove(const T& data) {
    // if tree is empty
    if (root == NULL)
        return 0;
    else {
        if (root->data == data) {
            Node<T> *auxRoot = new Node<T>();
            this->root = auxRoot->left;
            Node<T> *removedNode = root->remove(data, auxRoot);
            root = auxRoot->left;
            if (removedNode != NULL) {
                delete removedNode;
                return true;
            }
            else
                return false;
        }
        else {
            Node<T> *removedNode = root->remove(data, NULL);
            if (removedNode != NULL) {
                delete removedNode;
                return true;
            }
            else
                return false;
        }
    }
}

// recursive function used by myBST<T>::remove
template<class T>
Node<T>* Node<T>::remove(const T& data, Node<T> *node) {
    if (data < this->data) {
        if (left != NULL)
            return left->remove(data, this);
        else
            return NULL;
    }
    else if (data > this->data) {
        if (right != NULL)
            return right->remove(data, this);
        else
            return NULL;
    }
    else {
        if (left != NULL && right != NULL) {
            this->data = right->minValue();
            return right->remove(this->data, this);
        }
        else if (node->left == this) {
            node->left = (left != NULL) ? left : right;
            return this;
        }
        else if (node->right == this) {
            node->right = (left != NULL) ? left : right;
            return this;
        }
    }
}

// find minimum value of tree (left-most node in sub-tree)
template<class T>
T Node<T>::minValue() {
    if (left == NULL)
        return data;
    else
        return left->minValue();
}

#endif /* BST_hpp */
