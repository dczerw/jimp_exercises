//
// Created by dawid on 05.06.17.
//

#include "TeacherHash.h"
#include<iostream>

using ::academia::Teacher;
using ::academia::TeacherId;
using ::academia::TeacherHash;
using ::std::literals::string_literals::operator""s;


int main(){
    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
    const TeacherHash hash {};
    size_t hash_value = hash(s1);
    

    return 0;


}