//
// Created by dawid on 28.03.17.
//

#ifndef JIMP_EXERCISES_FAMILY_H
#define JIMP_EXERCISES_FAMILY_H

#include <string>

class Dziecko
{
private:

    std::string imie;
    std::string nazwisko;
    std::string szkola;
    int wiek;

    friend class Rodzic;
    
public:
    Dziecko();

};

class Rodzic
{
private:

    std::string imie;
    std::string nazwisko;
    int wiek;
    Dziecko dziecko_;
    
public:
    Rodzic();
    zmien

};

#endif //JIMP_EXERCISES_FAMILY_H
