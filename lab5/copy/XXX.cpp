//
// Created by dawid on 28.03.17.
//

#include "XXX.h"

XXX::XXX() : name_{new char[1024]} {

}

XXX::XXX(int param) {

}

XXX::XXX(const std::string name) {

}

XXX::XXX(const XXX &xxx) {

    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);

}

XXX::XXX(XXX &&xxx) : name_{nullptr} {
    swap(name_,xxx.name_);
    //Bardzo popularna szutczka
    //wiemy, ze za chwilę xxx zostanie zniszczony
    //za pomocą destrukotra, więc inicjalizujemy
    //this na nullptr i wymieniamy się z xxx
    //delete nullptr jest bezpieczna operacją i nic się nie stanie...
}

XXX &XXX::operator=(const XXX &xxx) {
    if (this == &xxx) {
        return *this;
    }
    //w przyciwynym wypadku mamy x = y;
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie kopiowanie, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}

XXX &XXX::operator=(XXX &&xxx) {
    //jeśli ktoś wpadł na pomsył x = move(x);
    if (this == &xxx) {
        return xxx;
    }
    //w przyciwynym wypadku mamy x = move(y);
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie przenosimy stan, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    name_ = nullptr;
    swap(name_,xxx.name_);
}

XXX::~XXX() {
    delete [] name_;
}
