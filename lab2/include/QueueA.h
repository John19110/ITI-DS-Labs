
#ifndef QUEUEA_H
#define QUEUEA_H

#include <iostream>


class QueueA{


private:
    int* items;
    int front;
    int rear;
    int size;
    int count;

public:

    QueueA();
    QueueA(int size);
    ~QueueA();

    void Enqueue(int value);
    int Dequeue();
    int Peek();

    bool IsEmpty();
    bool IsFull();
    int GetCount();
    void Display();

    QueueA(const QueueA&) = delete;
    QueueA& operator=(const QueueA&) = delete;
};


#endif
