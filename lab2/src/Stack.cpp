
#include "Stack.h"
#include <iostream>

using namespace std;

// Constructor
Stack::Stack()
{
    items = new LinkedList::LinkedList();
}

// Push
void Stack::push(int data)
{
    items->add(data);
}

// Pop
int Stack::pop(int* data)
{
    if (isEmpty())
        return 0;

    // Save the value before deleting the node
    *data = items->tail->data;

    items->RemoveLast();

    return 1;
}

// Peek
int Stack::peek(int* data)
{
    if (isEmpty())
        return 0;

    *data = items->tail->data;

    return 1;
}

// Check empty
bool Stack::isEmpty()
{
    return items->head == nullptr;
}

// Display
void Stack::display()
{
    items->Display();
}

// Destructor
Stack::~Stack()
{
    delete items;
}
