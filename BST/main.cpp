//
//  main.cpp
//  BST
//
//  Created by Robert Schwartz on 3/25/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "BST.hpp"

int main(int argc, const char * argv[])
{
    // create BST of type int
    BST<int> *mybst1 = new BST<int>;
    
    // insert 10 random values between 1-100
    for (int i = 0; i < 10; i++)
    {
        mybst1->insert(rand() % 100);
    }

    //search for value 62
    mybst1->search(62);

    std::cout << "\nBinary Tree printed using Inorder traversal: \n";
    mybst1->printInorder();
    std::cout << "\nBinary Tree printed using Preorder traversal: \n";
    mybst1->printPreorder();
    std::cout << "\nBinary Tree printed using Postorder traversal: \n";
    mybst1->printPostorder();

    //remove node with value of 62
    mybst1->remove(62);
    std::cout << std::endl;
    //search for node with value of 62 to show node was deleted
    mybst1->search(62);
    std::cout << std::endl;
    
    return 0;
}
