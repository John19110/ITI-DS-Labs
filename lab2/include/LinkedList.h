
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace LinkedList
{
    class Node
    {
    public:
        Node* prev;
        Node* next;
        int data;

        Node(int data);
    };

    class LinkedList
    {
    public:
        Node* head;
        Node* tail;

        LinkedList();
        ~LinkedList();

        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
        void Display();
        Node* search(int data);
        
        void add(int data);
        void InsertAfter(int data, int afterData);
        void InsertBefore(int data, int beforeData);
        
        int GetCount();
        int GetDataByIndex(int index);
        int GetFirst();

        int RemoveFirst();
        int RemoveLast();
    };
}

#endif
