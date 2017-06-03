//
// Created by dawid on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <string>
#include <unordered_map>
#include <iostream>


namespace nets
{
    class View
    {
    private:
        std::string text_;
    public:
        View();
        View(std::string text);
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
