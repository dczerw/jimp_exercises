//
// Created by Kuba on 21.04.2017.
//

#ifndef JIMP_EXERCISES_FORM_H
#define JIMP_EXERCISES_FORM_H

#include <iostream>

class Form
{
public:
    virtual void draw() const{};
};

class Circle : public Form
{
public:
    virtual void draw() const override;
};

class Triangle : public Form
{
public:
    virtual void draw() const override;
};

class Square : public Form
{
public:
    virtual void draw() const override;
};

#endif //JIMP_EXERCISES_FORM_H
