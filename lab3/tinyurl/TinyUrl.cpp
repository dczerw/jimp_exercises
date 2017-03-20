//
// Created by dawid on 19.03.17.
//

#include <cmath>
#include "TinyUrl.h"

//extern std::array<char, 6> table;

namespace tinyurl {

    void NextHash(std::array<char, 6> *state) {
        for (int i = 5; i >= 0; i--) {
            if ((*state)[i] == 122) (*state)[i] = 48;
            else {
                if ((*state)[i] == 57) (*state)[i] = 64;
                else if ((*state)[i] == 90) (*state)[i] = 96;
                (*state)[i] = (*state)[i] + 1;
                break;
            }
        }
    }

    std::unique_ptr<TinyUrlCodec> Init()
    {
        std::unique_ptr<TinyUrlCodec> pointer = std::make_unique<TinyUrlCodec>();
        for(int i=0; i<6; i++)
        {
            pointer->hash_array[i]='0';
        }
        return pointer;
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec)
    {

        std::string hash;
        for (auto character : (*codec)->hash_array) {
                hash+=character;
        }
        NextHash(&((*codec)->hash_array));
        return hash;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
    {
        

    }

    int GetDecimalFrom62System(std::unique_ptr<TinyUrlCodec> *codec)
    {
        int decimal=0;
        for(int i=5; i>=0; i--)
        {
            if((*codec)->hash_array[i] >= 48 and (*codec)->hash_array[i]<=57) decimal+=((*codec)->hash_array[i]-48)*pow(10,5-i);
            //std::cout<<decimal<<std::endl;
            else if ((*codec)->hash_array[i] >= 65 and (*codec)->hash_array[i]<=90) decimal+=((*codec)->hash_array[i]-48-7)*pow(10,5-i);
            else if((*codec)->hash_array[i] >= 97 and (*codec)->hash_array[i]<=122) decimal+=((*codec)->hash_array[i]-48-13)*pow(10,5-i);
        }
        return decimal;
    }

}