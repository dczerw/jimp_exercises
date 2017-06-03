//
// Created by dawid on 11.04.17.
//

#include <cstddef>
#include <vector>
#include <bits/unique_ptr.h>
#include <memory>
#include "ArrayFill.h"
namespace arrays {
    int arrays::UniformFill::Value(int index) const {

        return value_;
    }

    int arrays::IncrementalFill::Value(int index) const {
        return step_*index+offset_;
    }

    void FillArray(std::size_t size, const arrays::ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (std::size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int SquaredFill::Value(int index) const {
        return index*index*a_+b_;
    }

    int RandomFill::Value(int index) const {
        return (*uniform_)(*engine_);
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> p1,
                           std::unique_ptr<std::uniform_int_distribution<int>> p2)
    {
        engine_ = move(p1);
        uniform_ = move(p2);

    }


}