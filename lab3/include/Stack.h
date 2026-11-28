
#ifndef STACK_H
#define STACK_H

#include "Linkedlist.h"

class Stack
{
private:
    LinkedList::LinkedList* items;

public:
    Stack();
    ~Stack();

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(int data);
    int pop(int* data);
    int peek(int* data);

    bool isEmpty();
    void display();
};

#endif
