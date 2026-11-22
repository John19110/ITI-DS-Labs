
#include "../include/Linkedlist.h"

using namespace std;

namespace LinkedList
{
    Node::Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    LinkedList::LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    LinkedList::~LinkedList()
    {
        Node* cursor = head;

        while (cursor != nullptr)
        {
            Node* temp = cursor;
            cursor = cursor->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    void LinkedList::Display()
    {
        cout << "Forward: ";

        Node* cursor = head;

        while (cursor != nullptr)
        {
            cout << cursor->data << " <-> ";
            cursor = cursor->next;
        }

        cout << "NULL" << endl;
    }

    // Search
    Node* LinkedList::search(int data)
    {
        Node* cursor = head;

        while (cursor != nullptr)
        {
            if (cursor->data == data)
                return cursor;

            cursor = cursor->next;
        }

        return nullptr;
    }

    // Add at the end
    void LinkedList::add(int data)
    {
        Node* N = new Node(data);

        if (head == nullptr)
        {
            head = N;
            tail = N;
            return;
        }

        N->prev = tail;
        tail->next = N;
        tail = N;
    }

    // Insert after a given value
    void LinkedList::InsertAfter(int data, int afterData)
    {
        Node* existing = search(afterData);

        if (existing == nullptr)
            return;

        Node* N = new Node(data);

        N->prev = existing;
        N->next = existing->next;

        if (existing->next != nullptr)
            existing->next->prev = N;
        else
            tail = N;

        existing->next = N;
    }

    // Insert before a given value
    void LinkedList::InsertBefore(int data, int beforeData)
    {
        Node* existing = search(beforeData);

        if (existing == nullptr)
            return;

        Node* N = new Node(data);

        N->next = existing;
        N->prev = existing->prev;

        if (existing->prev != nullptr)
            existing->prev->next = N;
        else
            head = N;

        existing->prev = N;
    }

    // Get count
    int LinkedList::GetCount()
    {
        int count = 0;

        Node* cursor = head;

        while (cursor != nullptr)
        {
            count++;
            cursor = cursor->next;
        }

        return count;
    }

    // Get data by index
    int LinkedList::GetDataByIndex(int index)
    {
        if (index < 0)
            return -1;

        Node* cursor = head;
        int i = 0;

        while (cursor != nullptr)
        {
            if (i == index)
                return cursor->data;

            i++;
            cursor = cursor->next;
        }

        return -1;
    }

int LinkedList::GetFirst()
{
    if (head == nullptr)
        return -1;

    return  head->data;

}



    // Remove last node
    int LinkedList::RemoveLast()
    {
        if (tail == nullptr)
            return -1;

        int removedData = tail->data;

        Node* temp = tail;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;

        return removedData;
    }
int LinkedList::RemoveFirst()
{
    if (head == nullptr)
        return -1;

    int removedData = head->data;

    Node* temp = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;

    return removedData;
}
    
}
