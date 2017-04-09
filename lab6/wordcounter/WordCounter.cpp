//
// Created by dawid on 06.04.17.
//

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

    WordCounter::WordCounter(std::string localization) {
        std::ifstream file;
        file.open(localization, std::ios::in);
        if (!file) {
            std::cout << "File doesnt exist" << std::endl;
        } else {
            std::string word_str;
            Word word;
            bool is_found = false;

            while (file >> word_str) {
                for (auto &n : counter_) {
                    if (n.first.GetWord() == word_str) {
                        n.second++;
                        is_found = true;
                    }
                }

                if (!is_found) {
                    word.SetWord(word_str);
                    AddWord(word);
                }
                is_found = false;
            }
        }
    }

    WordCounter::~WordCounter() {

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

    void Counts::SetCounts(int number) {
        number_ = number;
    }


    void WordCounter::AddWord(Word word) {
        Counts number(1);
        counter_.emplace(word, number);
    }

    bool Word::operator<(const Word &rhs) const {
        return true;
    }

    Counts &Counts::operator++(int) {
        number_ = number_ + 1;
    }

    int WordCounter::operator[](std::string word) {
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
            //std::cout<<n.first.GetWord()<<" "<<n.second.GetCounts()<<std::endl;
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
        //for(auto n : elements) AddWord(n);
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

    int WordCounter::Words() {
        return 0;
    }

}
