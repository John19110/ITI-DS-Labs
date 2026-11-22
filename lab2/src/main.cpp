
#include <iostream>
#include "Stack.h"
#include "../include/QueueA.h"
#include "../include/QueueL.h"
using namespace std;

int main()
{
    Stack s;
   
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();
    int p;
    s.pop(&p);
    cout <<p<<endl;
    s.display();

cout<<"============================================";




    cout << "\n========== ARRAY QUEUE TEST ==========\n";

    QueueA q(5);


    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Display();


    cout << "\n3. Peek: " << q.Peek() << endl;

    cout  << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;

    q.Display();

   
    q.Enqueue(60);
    q.Enqueue(70);

    q.Display();

    cout  << q.GetCount() << endl;

   
    while (!q.IsEmpty())
    {
        cout  << q.Dequeue() << endl;
    }

    // 8. Empty Queue
    cout << "\n8. Is Empty: "
         << (q.IsEmpty() ? "Yes" : "No") << endl;

    q.Display();

    cout << "======================================\n";



    
 cout << "\n========== LINKED LIST QUEUE TEST ==========\n";

    QueueL ql;

    // 1. Enqueue
    cout << "\n1. Enqueue elements:\n";

    ql.Enqueue(100);
    ql.Enqueue(200);
    
    ql.Display();

    cout  << ql.Peek() << endl;

    cout  << ql.Dequeue() << endl;

    ql.Display();

   
    ql.Enqueue(500);
    ql.Enqueue(600);

    ql.Display();

    cout  << ql.GetCount() << endl;


    while (!ql.IsEmpty())
    {
        cout << ql.Dequeue() << endl;
    }

         cout<< (ql.IsEmpty() ? "Yes" : "No") << endl;

    ql.Display();

 
    ql.Enqueue(888);

    ql.Display();

    cout << "============================================\n";
    return 0;
}


