//
// Created by Kuba on 06.06.2017.
//

#include "ArabicRoman.h"

std::string arabicToRoman(int arabic) {
    int i = 0,
            j = 0;
    
    if ((arabic > 3999) || (arabic <= 0))
    {
        return NULL;
    }

    while ((arabic) && (i < ROMAN_N))
    {
        if(arabic >= arabic[i])
        {
            arabic -= arabic[i];
            result[j++] = roman[i];
        }
        else if ((i%2 == 0) &&
                 (i<ROMAN_N-2) && // 9xx condition
                 (arabic >= arabic[i] - arabic[i+2]) &&
                 (arabic[i+2] != arabic[i] - arabic[i+2]))
        {
            arabic -= arabic[i] - arabic[i+2];
            result[j++] = roman[i+2];
            result[j++] = roman[i];
            i++;
        }
        else if ((i%2 == 1) &&
                 (i<ROMAN_N-1) && //4xx condition
                 (arabic >= arabic[i] - arabic[i+1]) &&
                 (arabic[i+1] != arabic[i] - arabic[i+1]))
        {
            arabic -= arabic[i] - arabic[i+1];
            result[j++] = roman[i+1];
            result[j++] = roman[i];
            i++;
        }
        else
        {
            i++;
        }
    }
    result[j++] = 0;

    return result;
}

int romanToArabic(std::string roman) {
    int arabic = 0;
    for(int i = 0; i <= roman.size(); i++)
    {
        if(roman[i] == 'I' and roman[i+1] == 'V')
        {
            arabic+=4;
            i++;
        }
        else if(roman[i] == 'I' and roman[i+1] == 'X')
        {
            arabic+=9;
            i++;
        }
        else if(roman[i] == 'X' and roman[i+1] == 'L')
        {
            arabic+=40;
            i++;
        }
        else if(roman[i] == 'X' and roman[i+1] == 'C')
        {
            arabic+=90;
            i++;
        }
        else if(roman[i] == 'C' and roman[i+1] == 'D')
        {
            arabic+=400;
            i++;
        }
        else if(roman[i] == 'C' and roman[i+1] == 'M')
        {
            arabic+=900;
            i++;
        }
        else if(roman[i] == 'I')
        {
            arabic++;
        }
        else if(roman[i] == 'V')
        {
            arabic+=5;
        }
        else if(roman[i] == 'X')
        {
            arabic+=10;
        }
        else if(roman[i] == 'L')
        {
            arabic+=50;
        }
        else if(roman[i] == 'C')
        {
            arabic+=100;
        }
        else if(roman[i] == 'D')
        {
            arabic+=500;
        }
        else if(roman[i] == 'M')
        {
            arabic+=1000;
        }
        else if(!(roman[i]))
        {
            break;
        }
    }
    return arabic;
}
