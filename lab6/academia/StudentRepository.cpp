//
// Created by dawid on 03.04.17.
//

#include <initializer_list>
#include <ostream>
#include <istream>
#include <iosfwd>
#include "StudentRepository.h"

namespace academia
{

    int ReadNumber(::std::istream* is) {
        int d;
        (*is) >> d;
        return d;
    }

    std::string ReadString(::std::istream* is)
    {
        std::string d;
        (*is) >> d;
        return d;
    }


    StudyYear::StudyYear(int year)
    {
        year_=year;
    }

    StudyYear &StudyYear::operator++()
    {
        year_++;
    }

    StudyYear &StudyYear::operator--()
    {
        year_--;
    }



    std::basic_istream<char, std::char_traits<char>> &operator>>(std::istream &is, StudyYear &student)
    {
        student.SetYear(ReadNumber(&is));
        return is;

    }

    std::basic_ostream<char, std::char_traits<char>> &operator<<(std::ostream &out, StudyYear &year)
    {
        out<<year.GetYear();
        return out;
    }

    int StudyYear::SetYear(int year)
    {
        year_=year;
    }

    int StudyYear::GetYear() const
    {
        return year_;
    }

    bool StudyYear::operator<(const StudyYear &year2) const
    {
        if(year_<year2.GetYear()) return true;
        else return false;
    }

    bool StudyYear::operator==(const StudyYear &year2) const {

        if(year_==year2.GetYear()) return true;
        else return false;
    }

    StudyYear::operator int() const {

        return year_;
    }

    Student::Student() {
        id_="None";
        first_name_="None";
        last_name_="None";
        program_="None";
        year_=StudyYear(1);

    }

    Student::Student(std::string id, std::string first_name, std::string last_name, std::string program, int year)
    {
        id_=id;
        first_name_=first_name;
        last_name_=last_name;
        program_=program;
        year_=StudyYear(year);

    }

    std::istream &operator>>(std::istream &is, Student &student)
    {

        student.SetId(ReadString(&is));
        student.SetFirstName(ReadString(&is));
        student.SetLastName(ReadString(&is));
        student.SetProgram(ReadString(&is));
        student.SetStudyYear(ReadNumber(&is));

    }

    std::ostream &operator<<(std::ostream &out, Student &student)
    {
        out<<"Student {id: \""<<student.GetId()<<"\", first_name: \""<<student.GetFirstName()<<"\", last_name: \""<<student.GetLastName()<<"\", program: \""<<student.GetProgram()<<"\", year: "<<student.GetStudyYear()<<"}";

        return out;
    }

    StudyYear::StudyYear() {
    year_=1;
    }

}