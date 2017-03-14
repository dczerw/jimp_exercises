//
// Created by dawid on 13.03.17.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
std::string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary);
void PrintVector(const vector<char> &v);

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary);


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
