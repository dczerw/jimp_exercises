//
// Created by Kuba on 05.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <regex>


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
        bool isSubtitleEndBeforeStart(int start_frame, int end_frame);
        bool isInvalidSubtitleLineFormat(std::string line);
        bool isNegativeFrameRate(int fps);
        bool isNumeric(const std::string& s);
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
    private:
        int line_;
    public:
        SubtitleEndBeforeStart(std::string msg, int line);
        virtual ~SubtitleEndBeforeStart(){};
        int  LineAt() const;
    };

    class InvalidSubtitleLineFormat : public std::runtime_error
    {
    public:
        InvalidSubtitleLineFormat(std::string msg) : std::runtime_error(msg){};
        virtual ~InvalidSubtitleLineFormat(){};
    };
    class MissingTimeSpecification : public std::runtime_error
    {
    public:
        MissingTimeSpecification(std::string msg) : std::runtime_error(msg){};
        virtual ~MissingTimeSpecification(){};
    };
    class OutOfOrderFrames : public std::runtime_error
    {
    public:
        OutOfOrderFrames(std::string msg) : std::runtime_error(msg){};
        virtual ~OutOfOrderFrames(){};
    };

    class NegativeFrameRateThrowsIlegalArgument : public std::runtime_error
    {
    public:
        NegativeFrameRateThrowsIlegalArgument(std::string msg) : std::runtime_error(msg){};
        virtual ~NegativeFrameRateThrowsIlegalArgument(){};
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
