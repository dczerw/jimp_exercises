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

        while(getline(*in,line))
        {

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
        }
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)
    {
        std::string line;
        std::string start_hours,start_minutes,start_seconds,start_miliseconds;
        std::string end_hours,end_minutes,end_seconds,end_miliseconds;
        int line_nr=1;
        while(getline(*in, line))
        {
            if(line_nr==1)
            {
                *out<<line<<std::endl;
                line_nr++;
                continue;
            }
            if(line_nr==2)
            {

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
        /*while(getline(*in, line))
        {
            switch(line_nr)
            {
                case 1:
                    *out<<line<<std::endl;
                    line_nr++;
                    break;
                case 2:
                    start_hours=line[0]+line[1];
                    start_minutes=line[3]+line[4];
                    start_seconds=line[6]+line[7];
                    start_miliseconds=line[9]+line[10]+line[11];
                    end_hours=line[17]+line[18];
                    end_minutes=line[20]+line[21];
                    end_seconds=line[23]+line[24];
                    end_miliseconds=line[26]+line[27]+line[28];

                    if(atoi(start_miliseconds.c_str())+shift>999)
                    {
                        start_miliseconds=std::to_string(atoi(start_miliseconds.c_str())+shift-1000);
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

                    if(atoi(end_miliseconds.c_str())+shift>999)
                    {
                        end_miliseconds=std::to_string(atoi(end_miliseconds.c_str())+shift-1000);
                        end_seconds=std::to_string(atoi(end_seconds.c_str())+1);
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

                    *out<<start_hours<<"."<<start_minutes<<"."<<start_seconds<<","<<start_miliseconds<<" --> "<<
                        end_hours<<"."<<end_minutes<<"."<<end_seconds<<","<<end_miliseconds<<std::endl;

                    line_nr++;
                    break;
                case 3:
                    *out<<line<<std::endl;
                    line_nr++;
                    break;
                case 4:
                    *out<<line<<std::endl;
                    line_nr++;
                    break;
                case 5:
                    *out<<std::endl;
                    line_nr=0;
                    break;
            }


        }
         */
    }

}