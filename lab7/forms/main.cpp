//
// Created by Kuba on 21.04.2017.
//

#include "Form.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

int main()
{
    Circle circle;
    Square square;
    Triangle triangle;

    std::vector<Form*> list;
    srand(time(NULL));
    int random;
    for(int i=0; i<20; i++)
    {
        random=rand()%3;
        switch(random)
        {
            case 0: {
                list.emplace_back(&circle);
                break;
            }
            case 1: {
                list.emplace_back(&triangle);
                break;
            }
            case 2: {
                list.emplace_back(&square);
                break;
            }
        }
    }

    for(auto n : list)
    {
        n->draw();
    }

    return 0;
}