//
//  Node.cpp
//  Node
//
//  Created by Robert Schwartz on 3/25/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include "Node.hpp"

// recursive function used by myBST<T>::remove
template<class T>
Node<T>* Node<T>::remove(const T& data, Node<T> *node)
{
    if (data < this->data)
    {
        if (left != NULL)
        {
            return left->remove(data, this);
        }
        else return NULL;
    }
    else if (data > this->data)
    {
        if (right != NULL)
        {
            return right->remove(data, this);
        }
        else return NULL;
    }
    else
    {
        if (left != NULL && right != NULL)
        {
            this->data = right->minValue();
            return right->remove(this->data, this);
        }
        else if (node->left == this)
        {
            node->left = (left != NULL) ? left : right;
            return this;
        }
        else if (node->right == this)
        {
            node->right = (left != NULL) ? left : right;
            return this;
        }
    }
}

// find minimum value of tree (left-most node in sub-tree)
template<class T>
T Node<T>::minValue()
{
    if (left == NULL)
    {
        return data;
    }
    else return left->minValue();
}
