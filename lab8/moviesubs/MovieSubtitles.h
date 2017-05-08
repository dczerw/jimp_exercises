//
// Created by Kuba on 05.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>

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
        bool isNegativeFrameAfterShift(int start_frame_shift, int end_frame_shift);
    };

    class SubRipSubtitles : public MovieSubtitles
    {
    public:
        virtual void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out) override;
    };

    class NegativeFrameAfterShift : public std::runtime_error
    {
    public:
        NegativeFrameAfterShift(std::string msg) : std::runtime_error(msg){};
        virtual ~NegativeFrameAfterShift(){};
    };

    class SubtitleEndBeforeStart : public std::runtime_error
    {
    public:
        SubtitleEndBeforeStart(std::string msg) : std::runtime_error(msg){};
        virtual ~SubtitleEndBeforeStart(){};
        int  LineAt() const;
    };

    class InvalidSubtitleLineFormat : public std::runtime_error
    {
    public:
        InvalidSubtitleLineFormat(std::string msg) : std::runtime_error(msg){};
        virtual ~InvalidSubtitleLineFormat(){};
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
