//
// Created by dawid on 03.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
#include <algorithm>

namespace pool
{

    class TextPool
    {
    private:
        std::vector<std::string> pool_;

    public:
        TextPool();
        TextPool(const TextPool &textpool)=delete;
        //2. konstruktor przenoszący
        TextPool(TextPool &&textpool);
        //3. operator przypisania kopiujący
        TextPool &operator=(const TextPool &textpool)=delete;
        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&textpool);
        //5. Destruktor
        ~TextPool();
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
        TextPool(const std::initializer_list<std::string> &elements) : pool_{elements} {

            int index=-1;
            int size=0;

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

    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
