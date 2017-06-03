//
// Created by dawid on 28.03.17.
//

#include "Family.h"

Dziecko::Dziecko() {
    imie="none";
    nazwisko="none";
    szkola="none";
    wiek=0;

}

Rodzic::Rodzic() {
    imie="none";
    nazwisko="none";
    wiek=0;
    Dziecko nowy;
    dziecko_=nowy;

}
