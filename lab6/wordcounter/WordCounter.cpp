//
// Created by dawid on 06.04.17.
//

#include <set>
#include "WordCounter.h"

namespace datastructures {

    Word::Word() {
        word_ = "";
    }

    Word::Word(std::string word) {
        word_ = word;
    }

    Word::~Word() {
        word_ = "";
    }

    Counts::Counts() {
        number_ = 0;
    }

    Counts::Counts(int number) {
        number_ = number;
    }

    Counts::~Counts() {
        number_ = 0;
    }

    WordCounter::WordCounter() {
    }

    WordCounter::WordCounter(const std::string &localization) {
        std::ifstream file;
        file.open(localization, std::ios::in);
        if (!file) {
            std::cout << "File doesnt exist" << std::endl;
        } else {
            std::string word_in, word_noin; // word_in - with interpunction, word_noin - without interpunction characters
            int i=0;
            Word word;
            bool is_found = false;

            while (file >> word_in) {
                while(word_in[i]!='\0')
                {
                    if((word_in[i]>47 and word_in[i]<58) or (word_in[i]>64 and word_in[i]<91) or (word_in[i]>96 and word_in[i]<123)) word_noin+=word_in[i];
                    i++;
                }


                for (auto &n : counter_) {
                    if (n.first.GetWord() == word_noin) {
                        n.second++;
                        is_found = true;
                    }
                }

                if (!is_found) {
                    word.SetWord(word_noin);
                    AddWord(word);
                }
                is_found = false;
                word_in="";
                word_noin="";
                i=0;
            }
        }
        file.close();
    }

    WordCounter::~WordCounter() {
    counter_.clear();
    }

    std::string Word::GetWord() const {
        return word_;
    }

    void Word::SetWord(std::string word) {
        word_ = word;
    }

    int Counts::GetCounts() {
        return number_;
    }


    void WordCounter::AddWord(Word word) {
        Counts number(1);
        counter_.emplace(word, number);
    }

    bool Word::operator<(const Word &rhs) const {
        return GetWord()<rhs.GetWord();
    }

    Counts &Counts::operator++(int) {
        number_ = number_ + 1;
        return *this;
    }

    int WordCounter::operator[](const std::string &word) {
        for (auto n : counter_) {
            if (n.first.GetWord() == word) return n.second.GetCounts();
        }
        return 0;
    }

    bool Counts::operator<(const Counts &rhs) const {
        return number_ < rhs.number_;
    }

    bool Counts::operator>(const Counts &rhs) const {
        return number_ > rhs.number_;
    }

    bool Counts::operator==(const Counts &rhs) const {
        return number_ == rhs.number_;
    }

    std::map<Word, Counts> WordCounter::GetMap() {
        return counter_;
    }

    std::ostream &operator<<(std::ostream &output, WordCounter &wc) {

        std::list<std::pair<Word, Counts>> tmp;

        for (auto n : wc.GetMap()) {

            tmp.emplace_back(n);
        }
        tmp.sort(compare_nocase);
        for (auto n : tmp) {
            output << n.first.GetWord() << " " << n.second.GetCounts() << std::endl;
        }

        return output;
    }

    bool compare_nocase(std::pair<Word, Counts> one, std::pair<Word, Counts> two) {
        return one.second.GetCounts() > two.second.GetCounts();
    }

    int WordCounter::DistinctWords()
    {
        int words=0;
        for (auto n : counter_)
        {
            words++;
        }

        return words;

    }

    int WordCounter::TotalWords()
    {

        int words=0;
        for(auto n : counter_)
        {
            words+=n.second.GetCounts();
        }

        return words;
    }

    WordCounter::WordCounter(const std::initializer_list <const Word> &elements)
    {
        bool is_found=false;
        for(auto n : elements)
        {
            for(auto &v : counter_)
            {
                if(n.GetWord()==v.first.GetWord())
                {
                    is_found=true;
                    v.second++;
                }
            }
            if(!is_found)
            {
                AddWord(n);
            }
            is_found=false;
        }
    }

    std::set<Word> WordCounter::Words() {

        std::set<Word> sorted;
        for(auto n: counter_)
        {
            sorted.emplace(n.first);
        }


        return sorted;
    }

    bool Word::operator==(const Word &word) const {
        if(GetWord()==word.GetWord()) return true;
        else return false;
    }


    WordCounter WordCounter::FromInputStream(std::istream *input) {
        WordCounter wc;
        std::string word_in, word_noin; // word_in - with interpunction, word_noin - without interpunction characters
        int i=0;
        Word word;
        bool is_found = false;

        while (*input >> word_in) {
            while(word_in[i]!='\0')
            {
                if((word_in[i]>47 and word_in[i]<58) or (word_in[i]>64 and word_in[i]<91) or (word_in[i]>96 and word_in[i]<123)) word_noin+=word_in[i];
                i++;
            }


            for (auto &n : wc.GetMap()) {
                if (n.first.GetWord() == word_noin) {
                    wc.increment(n.first);
                    is_found = true;
                }
            }

            if (!is_found) {
                word.SetWord(word_noin);
                wc.AddWord(word);
            }
            is_found = false;
            word_in="";
            word_noin="";
            i=0;
        }

        return wc;
    }

    void WordCounter::increment(const Word &word)
    {
        counter_[word]++;
    }

}
