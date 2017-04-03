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
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
        TextPool(const std::initializer_list<std::string> &elements) : pool_{elements} {

        }

    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
