
#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include "Linkedlist.h"


    class QueueL
    {
    private:
        LinkedList::LinkedList* list;
        int count;

    public:
        QueueL();

        void Enqueue(int value);
        int Dequeue();
        int Peek();

        bool IsEmpty();
        int GetCount();
        void Display();

        QueueL(const QueueL&) = delete;
        QueueL& operator=(const QueueL&) = delete;
    };


#endif
