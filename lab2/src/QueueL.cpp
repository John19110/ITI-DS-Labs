
#include "../include/QueueL.h"
#include <iostream>

using namespace std;


    // Constructor
    QueueL::QueueL()
    {
        count = 0;
        list = new LinkedList::LinkedList();

    }

    // Enqueue
    void  QueueL::Enqueue(int value)
    {
        list->add(value);

        count++;
    }

    // Dequeue
    int QueueL::Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int removedValue = list->RemoveFirst();

        count--;

        return removedValue;
    }

    // Peek
    int QueueL::Peek()
    {
        if (IsEmpty())
            return -1;

        return list->GetFirst();
    }

    // IsEmpty
    bool QueueL::IsEmpty()
    {
        return count == 0;
    }

    // GetCount
    int QueueL::GetCount()
    {
        return count;
    }

    // Display
    void QueueL::Display()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Front -> ";

        list->Display();
    }

