#include <iostream>
using namespace std;

class Node {
 public:
  Node* prev;
  Node* next;
  int data;
  Node(int data) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

class LinkedList {
 public:
  Node* head;
  Node* tail;

  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void Display() {
    cout << "Forward: ";

    Node* cursor = head;

    while (cursor != nullptr) {
      cout << cursor->data << " <-> ";
      cursor = cursor->next;
    }

    cout << "NULL" << endl;
  }

  Node* search(int data) {
    if (head == nullptr) return nullptr;

    Node* cursor = this->head;

    while (cursor != nullptr) {
      if (data == cursor->data) {
        return cursor;
      }
      cursor = cursor->next;
    }

    return nullptr;
  }

  void add(int data) {
    if (head == nullptr) {
      Node* N = new Node(data);
      head = N;
      N->prev = nullptr;
      N->next = nullptr;
      tail = N;
    } else {
      InsertAfter(data, tail->data);
    }
  }
  void InsertAfter(int data, int afterData) {
    Node* existing = search(afterData);
    if (existing == nullptr) {
      return;
    }
    Node* N = new Node(data);

    N->prev = existing;
    N->next = existing->next;

    if (existing->next == nullptr)

    {
      tail = N;
      N->next = nullptr;
      existing->next = N;
    } else

    {
      N->next->prev = N;
      existing->next = N;
    }
  }

  // 2. indsert node before given node
  void InsertBefore(int data, int beforeData) {
    Node* existing = search(beforeData);
    if (existing == nullptr) {
      return;
    }
    Node* N = new Node(data);

    N->next = existing;

    if (existing->prev == nullptr)

    {
      head = N;
      N->prev = nullptr;
      existing->prev = N;
    } else

    {
      existing->prev->next = N;
      N->prev = existing->prev;
      existing->prev = N;
    }
  }

  // 3. get number of nodes
  int GetCount() {
    if (head == nullptr) return 0;

    int i = 0;

    Node* cursor = head;
    while (cursor != nullptr) {
      i++;

      cursor = cursor->next;
    }

    return i;
  }

  // 3. get number of nodes
  int GetDataByIndex(int index) {
    int x = GetCount();
    if (head == nullptr || index < 0 || index >= x) return -1;

    int i = 0;
    Node* cursor = head;
    while (cursor != nullptr) {
      if (i == index) return cursor->data;
      i++;
      cursor = cursor->next;
    }

    return i;
  }
};
int main() {
  LinkedList list;

  cout << "\n===== Testing add() =====\n";

  list.add(10);
  list.add(20);
  list.add(30);
  list.add(40);

  list.Display();

  cout << "\n===== Testing GetCount() =====\n";

  cout << "Count: " << list.GetCount() << endl;

  cout << "\n===== Testing search() =====\n";

  Node* result = list.search(20);

  if (result != nullptr)
    cout << "Found: " << result->data << endl;
  else
    cout << "Not found" << endl;

  cout << "\n===== Testing InsertAfter() =====\n";

  list.InsertAfter(25, 20);

  list.Display();

  cout << "\n===== Testing InsertBefore() =====\n";

  list.InsertBefore(5, 10);

  list.Display();

  cout << "\n===== Testing GetDataByIndex() =====\n";

  cout << "Index 0: " << list.GetDataByIndex(0) << endl;
  cout << "Index 2: " << list.GetDataByIndex(2) << endl;
  cout << "Index 5: " << list.GetDataByIndex(5) << endl;

  cout << "\n===== Testing Invalid Indexes =====\n";

  cout << "Index -1: " << list.GetDataByIndex(-1) << endl;
  cout << "Index 100: " << list.GetDataByIndex(100) << endl;

  cout << "\n===== Testing InsertBefore Head =====\n";

  list.InsertBefore(1, 5);

  list.Display();

  cout << "\n===== Testing InsertAfter Tail =====\n";

  list.InsertAfter(50, 40);

  list.Display();

  cout << "\n===== Final Result =====\n";

  cout << "Final count: " << list.GetCount() << endl;

  list.Display();

  return 0;
}