
#include "Stack.h"
#include <iostream>
#include"../include/LinkedList.h"
#include"../include/Sorting Algorithms.h"

using namespace std;

void SelectionSort(LinkedList::LinkedList& list)
{
 LinkedList:: Node* current = list.head;

    while (current != nullptr)
    {
      LinkedList::  Node* minNode = current;

       LinkedList:: Node* cursor = current->next;

        while (cursor != nullptr)
        {
            if (cursor->data < minNode->data)
            {
                minNode = cursor;
            }

            cursor = cursor->next;
        }

        // Swap the data
        int temp = current->data;
        current->data = minNode->data;
        minNode->data = temp;

        current = current->next;
    }
}




void BubbleSort(LinkedList::LinkedList& list)
{
    int size = list.GetCount();

    for (int i = 0; i < size - 1; i++)
    {
        LinkedList::  Node* current = list.head;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }

            current = current->next;
        }
    }
}
