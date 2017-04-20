//
// Created by dawid on 06.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <list>
#include <set>

namespace datastructures
{

    class Word {
    private:
        std::string word_;

    public:
        Word();
        Word(std::string word);
        ~Word();
        std::string GetWord() const;
        void SetWord(std::string word);
        bool operator<(const Word &rhs) const;
        bool operator==(const Word &word) const;
    };

    class Counts {
    private:
        int number_;

    public:
        Counts();
        Counts(int number);
        ~Counts();

        int GetCounts();

        Counts &operator++(int);
        bool operator<(const Counts &rhs) const;
        bool operator>(const Counts &rhs) const;
        bool operator==(const Counts &rhs) const;

    };

    class WordCounter {
    private:
        std::map<Word, Counts> counter_;

    public:
        WordCounter();
        WordCounter(const std::string &localization);
        WordCounter(const std::initializer_list<const Word> &elements);
        ~WordCounter();

        void AddWord(Word word);
        std::map<Word, Counts> GetMap();
        int operator[](const std::string &word);
        void increment(const Word &word);
        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();
        static WordCounter FromInputStream(std::istream *input);

    };

    std::ostream &operator<<(std::ostream &output, WordCounter &counter);
    bool compare_nocase(std::pair<Word, Counts> one, std::pair<Word, Counts> two);

}



#endif //JIMP_EXERCISES_WORDCOUNTER_H
