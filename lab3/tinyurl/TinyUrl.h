//
// Created by dawid on 19.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <iostream>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <vector>


namespace tinyurl {

    struct TinyUrlCodec {
        std::vector<std::string> url;
        std::array<char, 6> hash_array;
    };

    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(std::array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
    

}


#endif //JIMP_EXERCISES_TINYURL_H
