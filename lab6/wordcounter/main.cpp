//
// Created by dawid on 06.04.17.
//

#include "WordCounter.h"

using namespace std;
using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;

int main()
{

    std::ifstream is("/home/dawid/Desktop/nowy.txt");

    WordCounter wc = WordCounter::FromInputStream(&is);

    cout<<wc;

    return 0;
}
