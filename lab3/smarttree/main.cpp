//
// Created by dawid on 20.03.17.
//
#include <iostream>
#include "SmartTree.h"

using ::datastructures::SmartTree;
using ::datastructures::CreateLeaf;
using ::std::unique_ptr;
using ::std::cout;


int main()
{
    auto root = CreateLeaf(99);
    root = InsertLeftChild(std::move(root), CreateLeaf(100));
    root = InsertRightChild(std::move(root), CreateLeaf(88));
    root->left = InsertLeftChild(std::move(root->left), CreateLeaf(1234));
    //root->left = InsertRightChild(std::move(root->left), CreateLeaf(4321));
    //root->right = InsertLeftChild(std::move(root->right), CreateLeaf(897));
    //root->right = InsertRightChild(std::move(root->right), CreateLeaf(761));
    return 0;
}
