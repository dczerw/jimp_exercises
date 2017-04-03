//
// Created by dawid on 03.04.17.
//

#include "TextPool.h"

namespace pool
{
    TextPool::TextPool() {
;
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {

        for(int i=0; i<pool_.size(); i++)
        {
            if(str==pool_[i]) return pool_[i];
        }
        pool_.push_back(str);

        return pool_[pool_.size()-1];
    }

    size_t TextPool::StoredStringCount() const {
        return pool_.size();
    }




/*
    TextPool &TextPool::operator=(const TextPool &textpool) {
        return <#initializer#>;
    }

    TextPool &TextPool::operator=(TextPool &&textpool) {
        return <#initializer#>;
    }

    TextPool::~TextPool() {

    }*/
}
