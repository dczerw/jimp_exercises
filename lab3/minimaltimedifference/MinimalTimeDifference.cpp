//
// Created by dawid on 14.03.17.
//

#include "MinimalTimeDifference.h"
#include <cmath>


using namespace std;
regex pattern {R"((\d{1,2}):(\d{2}))"};
unsigned int ::minimaltimedifference::ToMinutes(std::string time_HH_MM) {
    smatch matches;
    if (regex_match(time_HH_MM, matches, pattern)) {


            return StringToInt(matches[1]) * 60 + StringToInt(matches[2]);

    }
}

int ::minimaltimedifference::StringToInt(string time) {

    int i = atoi(time.c_str());
    return i;
}

unsigned int ::minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times) {
    int wynik=1440;
    for(int i=0;i<times.size();i++)
    {
        for(int j=0;j<times.size();j++)
        {
            int _i=ToMinutes(times[i]);
            int _j=ToMinutes(times[j]);
            //if(min(ToMinutes(times[j])-ToMinutes(times[i]),min(ToMinutes(times[i]),ToMinutes(times[j]))+1440-max(ToMinutes(times[i]),ToMinutes(times[j]))<wynik and ToMinutes(times[j])-ToMinutes(times[i])>0) {
            if(min(_i-_j,min(_i,_j)+1440-max(_i,_j))<wynik and (_i-_j)>0)
            {
                wynik=min(_i-_j,min(_i,_j)+1440-max(_i,_j));

            }
        }
    }

    return wynik;
}
