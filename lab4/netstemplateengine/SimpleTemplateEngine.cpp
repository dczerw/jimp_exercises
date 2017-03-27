//
// Created by dawid on 27.03.17.
//

#include "SimpleTemplateEngine.h"

namespace nets
{

    View::View()
    {
        text_="";
    }

    View::View(std::string text)
    {
        text_=text;
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {

        std::string sentence, word;
        std::string key;
        int i=0;
        while(text_[i]!='\0')
        {
            if(text_[i]=='{' and text_[i+1]=='{')
            {
               i+=2;
                word="";
                while(text_[i]!='}' or text_[i+1]!='}')
                {
                    word+=text_[i];
                    if(text_[i]!='\0') i++;
                }
                sentence+=model.find(word)->second;
                i+=2;
            }
            sentence+=text_[i];
            i++;
        }

        return sentence;
    }
}