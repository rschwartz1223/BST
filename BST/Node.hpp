//
//  Node.hpp
//  Node
//  Custom self-balancing Binary Search Tree implementation.
//
//  Created by Robert Schwartz on 3/25/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

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
    
private:
    T data;
    Node<T> *left, *right;
};

#endif /* BST_hpp */
