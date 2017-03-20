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
    auto voronoi_shortened = tinyurl::Encode("https://en.wikipedia.org/wiki/Voronoi_diagram", &codec);
    auto movie_shortened = tinyurl::Encode("https://www.youtube.com/watch?v=cWDdd5KKhts", &codec);
    cout<<voronoi_shortened<<endl;
    cout<<movie_shortened<<endl;
    cout<<tinyurl::Decode(codec, voronoi_shortened)<<endl;
    cout<<tinyurl::Decode(codec, movie_shortened)<<endl;
    return 0;
}