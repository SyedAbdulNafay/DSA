#include <iostream>
using namespace std;

void Enqueue(int arr[5], int *front, int length, int value)
{
    if (*front >= length - 1)
    {
        cout << "stack overflow" << endl;
        return;
    }

    (*front)++;
    arr[*front] = value;
}

void Dequeue(int length, int *rear)
{
    if (*rear >= length)
    {
        return;
    }
    (*rear)++;
}

void Print(int arr[5], int rear, int front)
{
    for (int i = rear; i <= front; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {-1, -1, -1, -1, -1};
    int length = sizeof(arr) / sizeof(arr[0]);

    int front = -1;
    int rear = 0;

    while (true)
    {
        cout << "Press" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;

            Enqueue(arr, &front, length, value);
        }
        else if (option == 2)
        {
            Dequeue(length, &rear);
        }
        else if (option == 3)
        {
            Print(arr, rear, front);
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