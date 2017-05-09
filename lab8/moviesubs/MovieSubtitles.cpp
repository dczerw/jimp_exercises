//
// Created by Kuba on 05.05.2017.
//

#include "MovieSubtitles.h"

namespace moviesubs
{
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)
    {
        std::string line;
        std::string start_frame,end_frame;
        std::string start_frame_shift, end_frame_shift;
        int shift=int((double(miliseconds)/1000)*fps);
        int i=1;
        int line_nr=1;

        if(isNegativeFrameRate(fps)) throw std::invalid_argument("Invalid argument");

        while(getline(*in,line))
        {

            if(isInvalidSubtitleLineFormat(line)) throw InvalidSubtitleLineFormat("Invalid subtitle line format");

            while(line[i]!='}')
            {
                start_frame+=line[i];
                        i++;
            }

            i+=2;
            while(line[i]!='}')
            {
                end_frame+=line[i];
                i++;
            }
            i++;

            if(isNegativeFrameAfterShift(atoi(start_frame.c_str())+shift, atoi(start_frame.c_str())+shift)) throw
                        NegativeFrameAfterShift("Negative frame after shift.");
            else if(isSubtitleEndBeforeStart(atoi(start_frame.c_str()),atoi(end_frame.c_str()))) throw
                        SubtitleEndBeforeStart("At line "+std::to_string(line_nr)+": "+line,line_nr);

            start_frame_shift=std::to_string(atoi(start_frame.c_str())+shift);
            end_frame_shift=std::to_string(atoi(end_frame.c_str())+shift);
            *out << "{"+start_frame_shift+"}{"+end_frame_shift+"}";

            while(line[i]!='\0')
            {
                *out<<line[i];
                i++;
            }
            *out<<std::endl;
            i=1;
            start_frame="";
            start_frame_shift="";
            end_frame="";
            end_frame_shift="";
            line_nr++;
        }
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)
    {
        std::regex goodsubs("\\d\\d:\\d\\d:\\d\\d,\\d\\d\\d --> \\d\\d:\\d\\d:\\d\\d,\\d\\d\\d");
        if(fps<0) throw std::invalid_argument(" bad fps");
        std::string line;
        std::string start_hours,start_minutes,start_seconds,start_miliseconds;
        std::string end_hours,end_minutes,end_seconds,end_miliseconds;
        int line_nr=1;
        std::smatch result;
        int frames=1; // liczba klatek
        while(getline(*in, line))
        {
            if(line_nr==1)
            {
                *out<<line<<std::endl;
                if(atoi(line.c_str())!=frames) throw OutOfOrderFrames("out of order");
                frames++;
                line_nr++;
                continue;
            }
            if(line_nr==2)
            {
                if(not std::regex_search(line,result,goodsubs)) {
                    std::cout<<result[0];
                    throw InvalidSubtitleLineFormat("Cos poszlo zle.");
                }
                start_hours="";
                start_minutes="";
                start_seconds="";
                start_miliseconds="";
                end_hours="";
                end_minutes="";
                end_seconds="";
                end_miliseconds="";

                start_hours+=line[0]; start_hours+=line[1];
                start_minutes+=line[3]; start_minutes+=line[4];
                start_seconds+=line[6]; start_seconds+=line[7];
                start_miliseconds+=line[9]; start_miliseconds+=line[10]; start_miliseconds+=line[11];
                end_hours+=line[17]; end_hours+=line[18];
                end_minutes+=line[20]; end_minutes+=line[21];
                end_seconds+=line[23]; end_seconds+=line[24];
                end_miliseconds+=line[26]; end_miliseconds+=line[27]; end_miliseconds+=line[28];

                if(atoi(start_miliseconds.c_str())+miliseconds>999)
                {
                    start_miliseconds=std::to_string(atoi(start_miliseconds.c_str())+miliseconds-1000);
                    start_seconds=std::to_string(atoi(start_seconds.c_str())+1);
                    if(atoi(start_seconds.c_str())>59)
                    {
                        start_seconds[0]=0;
                        start_seconds[1]=0;
                        start_minutes=std::to_string(atoi(start_minutes.c_str())+1);
                        if(atoi(start_minutes.c_str())>59)
                        {
                            start_minutes[0]=0;
                            start_minutes[0]=0;
                            start_minutes=std::to_string(atoi(start_minutes.c_str())+1);
                        }
                    }
                }
                else start_miliseconds=std::to_string(atoi(start_miliseconds.c_str())+miliseconds);

                if(atoi(end_miliseconds.c_str())+miliseconds>999)
                {
                    end_miliseconds=std::to_string(atoi(end_miliseconds.c_str())+miliseconds-1000);
                    if(end_miliseconds.size()<3) end_miliseconds="0"+end_miliseconds;
                    end_seconds=std::to_string(atoi(end_seconds.c_str())+1);
                    if(end_seconds.size()<2) end_seconds="0"+end_seconds;
                    if(atoi(end_seconds.c_str())>59)
                    {
                        end_seconds[0]=0;
                        end_seconds[1]=0;
                        end_minutes=std::to_string(atoi(start_minutes.c_str())+1);

                        if(atoi(end_minutes.c_str())>59)
                        {
                            end_minutes[0]=0;
                            end_minutes[0]=0;
                            end_minutes=std::to_string(atoi(start_minutes.c_str())+1);
                        }
                    }
                }
                else
                {
                    end_miliseconds=std::to_string(atoi(end_miliseconds.c_str())+miliseconds);
                    if(end_miliseconds.size()<3) end_miliseconds="0"+end_miliseconds;
                }
                if(atoi(start_hours.c_str())>atoi(end_hours.c_str())) throw SubtitleEndBeforeStart("At line "+std::to_string(line_nr)+": "+line,line_nr);
                else if(atoi(start_minutes.c_str())>atoi(end_minutes.c_str())) throw SubtitleEndBeforeStart("At line "+std::to_string(line_nr)+": "+line,line_nr);
                else if(atoi(start_seconds.c_str())>atoi(end_seconds.c_str())) throw SubtitleEndBeforeStart("At line "+std::to_string(line_nr)+": "+line,line_nr);
                else if(atoi(start_miliseconds.c_str())>atoi(end_miliseconds.c_str())) throw SubtitleEndBeforeStart("At line "+std::to_string(line_nr)+": "+line,line_nr);
                


                *out<<start_hours<<":"<<start_minutes<<":"<<start_seconds<<","<<start_miliseconds<<" --> "<<
                    end_hours<<":"<<end_minutes<<":"<<end_seconds<<","<<end_miliseconds<<std::endl;
                line_nr++;
                continue;
            }
            if(line_nr>2)
            {
                *out<<line<<std::endl;
                if(line=="") line_nr=1;
                else line_nr++;
                continue;
            }

        }

    }

    bool MicroDvdSubtitles::isNegativeFrameAfterShift(int start_frame_shift, int end_frame_shift) {
        if(start_frame_shift<0 or end_frame_shift<0) return true;
        else return false;
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return line_;
    }

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(std::string msg, int line) : std::runtime_error(msg)
    {
        line_ = line;
    }

    bool MicroDvdSubtitles::isSubtitleEndBeforeStart(int start_frame, int end_frame) {
        if(end_frame<start_frame) return true;
        else return false;
    }

    bool MicroDvdSubtitles::isInvalidSubtitleLineFormat(std::string line) {
        int l_brackets=0;
        int r_brackets=0;
        std::string start_frame, end_frame;
        int i=0;

        while(line[i]!='\0')
        {
            if(line[i]=='{') l_brackets++;
            if(line[i]=='}') r_brackets++;
            i++;
        }
        if(l_brackets!=r_brackets) return true;
        else
        {
            if(l_brackets!=2 and l_brackets!=3) return true;
            if(r_brackets!=2 and r_brackets!=3) return true;
        }

        i=1;
        while(line[i]!='}')
        {
            start_frame+=line[i];
            i++;
        }

        i+=2;
        while(line[i]!='}')
        {
            end_frame+=line[i];
            i++;
        }
        if(isNumeric(start_frame)==false or isNumeric(end_frame)==false) return true;

        return false;
    }

    bool MicroDvdSubtitles::isNegativeFrameRate(int fps) {
        if (fps<0) return true;
        else return false;
    }

    bool MicroDvdSubtitles::isNumeric(const std::string &s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
}