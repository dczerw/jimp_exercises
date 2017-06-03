//
// Created by dawid on 11.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H
#include <ctime>
#include <cstdlib>
#include <random>
namespace arrays {

    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int offset = 0, int step = 1) : offset_{offset},step_{step} {}
        virtual int Value(int index) const override;
    private:
        int step_;
        int offset_;
    };
    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a = 1, int b = 0) : a_{a},b_{b} {}
        virtual int Value(int index) const override;
    private:
        int a_;
        int b_;
    };
    class RandomFill : public ArrayFill {
    public:
        //RandomFill(int value = 0) : value_{value} {}
        RandomFill(std::unique_ptr<std::default_random_engine> p1, std::unique_ptr<std::uniform_int_distribution<int>>p2);
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<std::default_random_engine> engine_;
        std::unique_ptr<std::uniform_int_distribution<int>> uniform_;

    };
    void FillArray(std::size_t size, const arrays::ArrayFill &filler, std::vector<int> *v);


}

#endif //JIMP_EXERCISES_ARRAYFILL_H
