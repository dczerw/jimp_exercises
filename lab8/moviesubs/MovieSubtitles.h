//
// Created by Kuba on 05.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <string>
#include <iostream>

namespace moviesubs
{
    class MovieSubtitles
    {
    public:
        virtual void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)=0;
    };

    class MicroDvdSubtitles : public MovieSubtitles
    {
    public:
        virtual void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out) override;
    };

    class SubRipSubtitles : public MovieSubtitles
    {
    public:
        virtual void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out) override;
    };


}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
