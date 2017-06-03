//
// Created by Kuba on 05.05.2017.
//

#include "Pesel.h"

namespace academia
{
    Pesel::Pesel(std::string pesel) {
    validatePESEL(pesel);
    }

    void Pesel::validatePESEL(std::string pesel)
    {
        int checksum=0, length=0;
        if(PeselLength(pesel,&length)) throw InvalidPeselLength(pesel, length);
        else if(PeselCharacter(pesel)) throw InvalidPeselCharacter(pesel);
        else if(PeselChecksum(pesel,&checksum)) throw InvalidPeselChecksum(pesel, checksum);
        pesel_=pesel;
    }

    bool Pesel::PeselChecksum(std::string pesel, int *checksum) {
        *checksum = 0;
        *checksum = 9 * ((int) pesel[0] - 48) + 7 * ((int) pesel[1] - 48) + 3 * ((int) pesel[2] - 48) +
               1 * ((int) pesel[3] - 48) +
               9 * ((int) pesel[4] - 48) + 7 * ((int) pesel[5] - 48) + 3 * ((int) pesel[6] - 48) +
               1 * ((int) pesel[7] - 48) + 9 * ((int) pesel[8] - 48) + 7 * ((int) pesel[9] - 48);
        if (*checksum % 10 != ((int) pesel[10] - 48)) {
            return true;
        } else {
            return false;
        }
    }

    bool Pesel::PeselLength(std::string pesel, int *length) {
        *length=pesel.length();
        if (pesel.length()!=11) return true;
        else return false;
    }

    bool Pesel::PeselCharacter(std::string pesel) {
        int i=0;
        while(pesel[i]!='\0')
        {
            if(pesel[i]<'0' or pesel[i]>'9') return true;
            i++;
        }
        return false;
    }

    InvalidPeselChecksum::InvalidPeselChecksum(std::string pesel, int checksum) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: " +
                                                                                                                      std::to_string(checksum)){};

    InvalidPeselLength::InvalidPeselLength(std::string pesel, int length) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " +
                                                                                                        std::to_string(length)){};

    InvalidPeselCharacter::InvalidPeselCharacter(std::string pesel) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") character set") {}
}

