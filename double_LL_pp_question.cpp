#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node *Insert(Node *head, int value)
{
    if (head == nullptr)
    {
        Node *node = new Node(value);
        return node;
    }

    head->next = Insert(head->next, value);
    head->next->prev = head;
    return head;
}

void Print(Node *head)
{
    if (head == nullptr)
        return;

    cout << head->data << " ";
    Print(head->next);
}

Node *Delete(Node *head, int value)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->data == value)
    {
        Node *temp = head->next;
        if (head->next != nullptr)
        {
            head->next->prev = head->prev;
        }
        delete head;
        return temp;
    }
    head->next = Delete(head->next, value);
    return head;
}

void MoveMinToHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    MoveMinToHead(head->next);
    if (head->data > head->next->data)
    {
        swap(head->data, head->next->data);
    }
}

void MoveMaxToHead(Node *head)
{
    if (head == nullptr || head->next == nullptr) return;
    
    MoveMaxToHead(head->next);

    if (head->data < head->next->data)
    {
        swap(head->data, head->next->data);
    }
    
}

int main()
{
    Node *head = nullptr;

    while (true)
    {
        cout << "1. Insert" << endl;
        cout << "2. Print" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Move Min to Head" << endl;
        cout << "5. Move Max to Head" << endl;
        cout << "0. Exit" << endl;

        int opt;
        cin >> opt;

        if (opt == 1)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            head = Insert(head, value);
        }
        else if (opt == 2)
        {
            Print(head);
            cout << endl;
        }
        else if (opt == 3)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            head = Delete(head, value);
        }
        else if (opt == 4)
        {
            MoveMinToHead(head);
        }
        else if (opt == 5)
        {
            MoveMaxToHead(head);
        }
        else if (opt == 0)
        {
            break;
        }
        else
        {
            cout << "Enter valid opt" << endl;
        }
    }

    return 0;
}
