
#include <iostream>
#include "../include/Stack.h"

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

    return 0;

}


