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
    //pointer->parent=nullptr;
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

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out)
    {
        if(unique_ptr!= nullptr)
        {
            //std::unique_ptr<SmartTree> tree_left = move(unique_ptr->left);
            PrintTreeInOrder(unique_ptr->left, out);
            *out<<unique_ptr->value<<", ";
            PrintTreeInOrder(unique_ptr->right, out);

            //std::unique_ptr<SmartTree> tree_right = move(unique_ptr->right);
            //PrintTreeInOrder(const std::unique_ptr<SmartTree> &tree_right, std::ostream *out);
        }
    }

}
