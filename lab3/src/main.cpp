
#include <iostream>
#include "../include/Stack.h"
#include"Sorting Algorithms.h"
using namespace std;


int main()
{
    Stack S;
    for (int i=5;i>=1;i--)
    {
        S.push(i);
        
    }
    int answer =1;
    int accumulator=0;
    S.peek(&accumulator);
    while (!S.isEmpty())
    {

        S.pop(&accumulator);

        answer*=accumulator;

    }
    cout <<answer;

    int arr[]= {10,5,3,4};

 



    LinkedList::LinkedList list;

    // Populate the linked list
    list.add(8);
    list.add(3);
    list.add(6);
    list.add(1);
    list.add(5);

    cout << "Original Linked List:\n";
    list.Display();

    // Test Selection Sort
    cout << "\n========== Selection Sort ==========\n";

    SelectionSort(list);

    cout << "After Selection Sort:\n";
    list.Display();

    // Add another unsorted sequence
    list.add(10);
    list.add(2);
    list.add(7);
    list.add(4);

    cout << "\nBefore Bubble Sort:\n";
    list.Display();

    // Test Bubble Sort
    cout << "\n========== Bubble Sort ==========\n";

    BubbleSort(list);

    cout << "After Bubble Sort:\n";
    list.Display();

    return 0;
}





