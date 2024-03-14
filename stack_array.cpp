#include <iostream>
using namespace std;

void arraySum(int (* stack)[size], int stop, int size)
{
    for (int i = 0; i < size; i++)
    {
        (*stack)[i] += stop;
    }
}

int main()
{
    int stack[5];
    int size = sizeof(stack)/sizeof(stack[0]);
    int (* pstack)[size] = &stack;
    
    // cout << (*pstack)[0] << endl;

    arraySum(pstack, 5, size)

    return 0;
}