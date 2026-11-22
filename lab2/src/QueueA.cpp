
#include "../include/QueueA.h"
#include <iostream>

using namespace std;
QueueA::QueueA()
{
    this->size = 10;

    items = new int[size];

    front = 0;
    rear = -1;
    count = 0;
}


QueueA::QueueA(int size)
{
    this->size = size;

    items = new int[size];

    front = 0;
    rear = -1;
    count = 0;
}

QueueA::~QueueA()
{
    delete[] items;
    items = nullptr;
}

void QueueA::Enqueue(int value)
{
    if (IsFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }

    rear = (rear + 1) % size;

    items[rear] = value;

    count++;
}

int QueueA::Dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    int removedValue = items[front];

    front = (front + 1) % size;

    count--;

    return removedValue;
}

// Peek
int QueueA::Peek()
{
    if (IsEmpty())
        return -1;

    return items[front];
}

// IsEmpty
bool QueueA::IsEmpty()
{
    return count == 0;
}

// IsFull
bool QueueA::IsFull()
{
    return count == size;
}

// GetCount
int QueueA::GetCount()
{
    return count;
}

// Display
void QueueA::Display()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Front -> ";

    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % size;

        cout << items[index] << " -> ";
    }

    cout << "NULL" << endl;
}
