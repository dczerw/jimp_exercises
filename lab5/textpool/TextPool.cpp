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

        std::experimental::string_view str_to_return;

        for(int i=0; i<pool_.size(); i++)
        {
            if(str==pool_[i])
            {
                str_to_return = pool_[i];
            return str_to_return;
            }
        }
        pool_.push_back(str);

        str_to_return = pool_[pool_.size()-1];

        return str_to_return;
    }

    size_t TextPool::StoredStringCount() const {
        return pool_.size();
    }

    TextPool::~TextPool() {
    pool_.clear();
    }

    TextPool::TextPool(TextPool &&textpool) {
        if(pool_!=textpool.pool_)
        {
            pool_.clear();
            std::swap(pool_, textpool.pool_);
        }

    }

    TextPool &TextPool::operator=(TextPool &&textpool) {

        if(pool_!=textpool.pool_)
        {
            pool_.clear();
            std::swap(pool_, textpool.pool_);
        }
        //return <#initializer#>;
    }

    TextPool::TextPool(const std::initializer_list<std::string> &elements) : pool_{elements} {


            for(int i=0; i<pool_.size()-1; i++)
            {
                for(int j=i+1; j<pool_.size(); j++)
                {
                    if(pool_[i]==pool_[j])
                    {
                        pool_.erase(pool_.begin() + j-1);
                    }
                }
            }

        }




}
