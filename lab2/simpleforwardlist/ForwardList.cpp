//
// Created by dawid on 06.03.17.
//

#include "ForwardList.h"
typedef struct tagListElement
{
    struct tagListElement *next;
    int data;
} ListElement;

typedef struct ForwardList
{
    ListElement *tail;
    int size;
}List;

ForwardList *CreateNode(int value)
{
    ListElement *tmp;
    tmp->data=value;
    return tmp;
}