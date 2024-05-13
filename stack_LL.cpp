#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

Node *Push(Node *head, int value)
{
    Node *node = new Node(value);
    if (head == nullptr)
    {
        return node;
    }
    node->next = head;
    return node;
}

void Pop(Node **head)
{
    if (*head == nullptr)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node *temp = (*head)->next;
    *head = (*head)->next;
    delete *head;
}

void Print(Node *head)
{
    if (head == nullptr)
        return;

    cout << head->data << " ";
    Print(head->next);
}

int main()
{
    Node *head = nullptr;
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
            int value;
            cout << "Enter value: ";
            cin >> value;
            head = Push(head, value);
        }
        else if (option == 2)
        {
            Pop(&head);
        }
        else if (option == 3)
        {
            Print(head);
            cout << endl;
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