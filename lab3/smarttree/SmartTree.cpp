//
// Created by dawid on 20.03.17.
//

#include "SmartTree.h"

namespace datastructures
{
    std::unique_ptr <SmartTree> CreateLeaf(int value)
{
    std::unique_ptr<SmartTree> pointer = std::make_unique<SmartTree>();
    pointer->value=value;
    pointer->parent=nullptr;
    pointer->left=nullptr;
    pointer->right=nullptr;
    return pointer;
}
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
    {
        tree->left=move(left_subtree);
        //left_subtree->parent=move(tree);
        return tree;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=move(right_subtree);
        //right_subtree->parent=move(tree);
        return tree;
    }

}
