//
// Created by Kuba on 05.05.2017.
//

#include "MovieSubtitles.h"
#include <memory>

using namespace std;

int main()
{

    unique_ptr<moviesubs::MovieSubtitles> subs = make_unique<moviesubs::SubRipSubtitles>();
    stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
    stringstream out;
    subs->ShiftAllSubtitlesBy(300, 24, &in, &out);

    std::string line;
    while(getline(out, line))
    {
        std::cout<<line;
    }



    return 0;
}

