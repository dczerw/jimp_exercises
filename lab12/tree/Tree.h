//
// Created by Kuba on 30.05.2017.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <bits/unique_ptr.h>
#include <memory>

namespace tree{
    template<typename T>
    class Tree{
    public:
        Tree(const T &data = T());
        void Insert(const T &elem);
        T Value() const;
        size_t Size();
        int Depth();

    private:
        T data_;
        std::unique_ptr<Tree<T>> l_child_;
        std::unique_ptr<Tree<T>> r_child_;
        size_t size_;
        int depth_;

    };

    template<typename T>
    void Tree<T>::Insert(const T &elem){
        std::unique_ptr<T> tmp = nullptr;
        while(l_child_!=nullptr or r_child_!=nullptr){
            if(elem<data_){
                if(l_child_==nullptr){
                    l_child_ = std::make_unique<Tree<T>>(elem);
                    break;
                }
                else{
                    l_child_->Insert(elem);
                }
            }
            if(elem>=data_){
                if(r_child_==nullptr){
                    r_child_ = std::make_unique<Tree<T>>(elem);
                    break;
                }
                else{
                    r_child_->Insert(elem);
                }
            }
        }
    }

    template<typename T>
    T Tree<T>::Value() const{
        return data_;
    };

    template<typename T>
    size_t Tree<T>::Size(){
        return size_;
    }

    template<typename T>
    int Tree<T>::Depth(){
        int max_left=0, max_right=0;
        if(l_child_==nullptr and r_child_==nullptr) return 1;
        else if(l_child_->Depth()>=r_child_->Depth()) return 1+l_child_->Depth();
        else return 1+r_child_->Depth();
    }

    template<typename T>
    Tree<T>::Tree(const T &data){
        data_=data;
        size_=1;
        l_child_ = nullptr;
        r_child_ = nullptr;
        depth_=1;

    }
}

#endif //JIMP_EXERCISES_TREE_H
