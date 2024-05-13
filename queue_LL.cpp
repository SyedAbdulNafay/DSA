#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int v)
    {
        data = v;
        next = nullptr;
    }
};

void Enqueue(Node **front, Node **rear, int value)
{
    Node *node = new Node(value);
    if (*front == nullptr)
    {
        *front = node;
        *rear = node;
        return;
    }
    (*front)->next = node;
    *front = node;
}

void Dequeue(Node **rear, Node **front)
{
    if (*rear == nullptr)
    {
        cout << "Stack Undeflow" << endl;
        return;
    }
    Node *temp = *rear;
    if ((*rear)->next == nullptr)
    {
        *rear = nullptr;
        *front = nullptr;
    }
    else
    {
        *rear = (*rear)->next;
    }
    delete temp;
}

void Print(Node *rear)
{
    Node *curr = rear;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Node *front = nullptr;
    Node *rear = nullptr;

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
            Enqueue(&front, &rear, value);
        }
        else if (option == 2)
        {
            Dequeue(&rear, &front);
        }
        else if (option == 3)
        {
            Print(rear);
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