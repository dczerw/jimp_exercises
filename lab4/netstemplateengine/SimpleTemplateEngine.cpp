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
                while(true)
                {
                    if(text_[i]=='}' and text_[i+1]=='}') break;
                    word+=text_[i];
                    if(text_[i]!='\0') i++;
                }

                auto search = model.find(word);
                if(search != model.end()) {
                    sentence+=search->second;
                }
                //sentence+=model.find(word)->second;
                i+=2;
            }

            sentence+=text_[i];
            if(text_[i]!='\0') i++;

        }
        int size = sentence.size();
        if(sentence[size-1]=='\0')  sentence.pop_back();


        return sentence;
    }
}