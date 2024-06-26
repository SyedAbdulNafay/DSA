#include <iostream>
using namespace std;

void Push(int arr[5], int length, int* top)
{
    if (*top >= length - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    (*top)++;
    cout << "Enter value: ";
    int value;
    cin >> value;
    arr[*top] = value;
}

void Pop(int length, int *top)
{
    if (*top < 0)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    (*top)--;
}

void Print(int arr[5], int top)
{
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int top = -1;
    int arr[5] = {-1, -1, -1, -1, -1};
    int length = sizeof(arr) / sizeof(arr[0]);

    while (true)
    {
        cout << "Press" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            Push(arr, length, &top);
        }
        else if (option == 2)
        {
            Pop(length, &top);
        }
        else if (option == 3)
        {
            Print(arr, top);
        }
        else if (option == 0)
        {
            break;
        }
        else
        {
            cout << "Enter valid option" << endl;
        }
    }

    return 0;
}