//
// Created by Kuba on 05.06.2017.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<class T, class C>
class SequentialIdGenerator{
public:
    SequentialIdGenerator(){
        counter_=C();
    };
    SequentialIdGenerator(C counter){
        counter_=counter;
    };
    T NextValue(){
        C tmp = counter_;
        ++counter_;
        return T(tmp);
    };
private:
    C counter_;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
