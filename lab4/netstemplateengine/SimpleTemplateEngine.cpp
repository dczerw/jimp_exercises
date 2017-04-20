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
        int i=0, j=0;
        while(text_[i]!='\0')
        {
            if(text_[i]=='{' and text_[i+1]=='{' and text_[i+2]!='{')
            {
               i+=2;
                word="";
                while(text_[i]!='}')
                {
                    word+=text_[i];
                    if(text_[i]!='\0') i++;
                }
                if(text_[i+1]!='}')
                {
                    sentence+="{{"+word+text_[i]+text_[i+1];
                }
                else {
                    auto search = model.find(word);
                    if (search != model.end()) {
                        sentence += search->second;
                    }
                }
                    i += 2;
            }

            sentence+=text_[i];
            if(text_[i]!='\0') i++;

        }
        int size = sentence.size();
        if(sentence[size-1]=='\0')  sentence.pop_back();


        return sentence;
    }
}