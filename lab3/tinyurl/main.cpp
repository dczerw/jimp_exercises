//
// Created by dawid on 19.03.17.
//

#include <iostream>
#include "TinyUrl.h"

using namespace std;

//std::array<char, 6> table {'0', '0', '0', '0', '0', '0'};

int main()
{
    auto codec = tinyurl::Init();
    for(int i=0; i<1000; i++) {
        auto voronoi_shortened = tinyurl::Encode("https://en.wikipedia.org/wiki/Voronoi_diagram", &codec);
        cout<<tinyurl::GetDecimalFrom62System(&codec)<<endl;
    }
    //auto movie_shortened = tinyurl::Encode("https://www.youtube.com/watch?v=cWDdd5KKhts", &codec);
    //cout<<tinyurl::GetDecimalFrom62System(&codec)<<endl;

    return 0;
}