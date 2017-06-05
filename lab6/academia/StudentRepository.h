//
// Created by dawid on 03.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <vector>
#include <istream>
#include <string>
#include <vector>

namespace academia
{
    class StudyYear
    {
    private:
        int year_;
    public:
        StudyYear();
        StudyYear(int year);
        StudyYear &operator++();
        StudyYear &operator--();
        bool operator<(const StudyYear &year2) const;
        bool operator==(const StudyYear &year2) const;
        int SetYear(int year);
        int GetYear() const;
        operator int() const;


    };

    class Student
    {
    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;
    public:
        Student();
        Student(std::string id, std::string first_name, std::string last_name, std::string progam, int year);

        std::string GetId() {return id_;}
        std::string GetFirstName() {return first_name_;}
        std::string GetLastName() {return last_name_;}
        std::string GetProgram() {return program_;}
        StudyYear GetStudyYear() {return year_.GetYear();}

        void SetId(std::string id) {id_=id;}
        void SetFirstName(std::string first_name) {first_name_=first_name;}
        void SetLastName(std::string last_name) {last_name_=last_name;}
        void SetProgram(std::string program) {program_=program;}
        void SetStudyYear(int year) {year_=StudyYear(year);}

    };

    class StudentRepository
    {
    private:
        std::vector<Student> repository_;
    };

    std::istream& operator>>(std::istream &is, StudyYear& year);
    std::ostream& operator<<(std::ostream &out, StudyYear& year);
    std::istream& operator>>(std::istream &is, Student& student);
    std::ostream& operator<<(std::ostream &out, Student& student);

}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H