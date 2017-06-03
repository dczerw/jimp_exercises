//
// Created by Kuba on 05.05.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

namespace academia
{
    class Pesel
    {
    private:
        std::string pesel_;
    public:
        Pesel(std::string pesel);

        void validatePESEL(std::string pesel);
        bool PeselChecksum(std::string pesel, int *checksum);
        bool PeselLength(std::string pesel, int *length);
        bool PeselCharacter(std::string pesel);
    };

    class AcademiaDataValidationError : public std::runtime_error
    {
    public:
        AcademiaDataValidationError(std::string msg) : std::runtime_error(msg){};
       virtual ~AcademiaDataValidationError(){};
    private:
        std::string msg_;
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError
    {
    public:
        InvalidPeselChecksum(std::string pesel="pesel", int checksum=0);
    private:
        std::string msg_;
    };

    class InvalidPeselLength : public AcademiaDataValidationError
    {
    public:
        InvalidPeselLength(std::string pesel="pesel", int length=0);
    private:
        std::string msg_;
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError
    {
    public:
        InvalidPeselCharacter(std::string pesel="pesel");
    private:
        std::string msg_;
    };


}

#endif //JIMP_EXERCISES_PESEL_H
