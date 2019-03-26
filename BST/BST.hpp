//
//  BST.hpp
//  BST
//
//  Created by Robert Schwartz on 3/25/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include "Node.hpp"
#include <stdio.h>

template<class T>
class BST
{
public:
    BST(){ root = 0; }
    void insert(const T data);
    void inorder(Node<T> *node);
    void preorder(Node<T> *node);
    void postorder(Node<T> *node);
    void printInorder();
    void printPreorder();
    void printPostorder();
    bool search(const T& data);
    bool remove(const T& value);
    
private:
    Node<T> *root;
};

#endif /* BST_hpp */
