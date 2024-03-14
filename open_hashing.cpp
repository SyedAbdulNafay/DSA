#include <iostream>
using namespace std;
#include <list>

struct Node
{
    int data;
    Node * next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Singly
{
    public:
        Node * head, * tail;
        Singly()
        {
            head = tail = NULL;
        }

        void AddNode(int data)
        {
            Node * ptr = new Node(data);
            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
                return;
            }
            tail->next = ptr;
            tail = ptr;
            return;
        }

        void Print()
        {
            if (head == NULL)
            {
                cout << "This index is empty" << endl;
                return;
            }
            Node * temp = head;
            while (temp != NULL)
            {
                if (temp != head)
                {
                    cout << "--->";
                }
                cout << temp->data;
                temp = temp->next;
            }
            cout << endl;
            return;
        }

        void Search(int data)
        {
            Node * temp = head;
            while (temp != NULL)
            {
                if (temp->data == data)
                {
                    cout << "Found" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Not found" << endl;
            return;
        }
};

int hashFunction(int data, int modFunction)
{
    return (data % modFunction);
}

int main()
{
    int n;
    Singly hashmap[10];
    bool loop = true;

    while (loop == true)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value: ";
            cin >> n;

            hashmap[hashFunction(n, 10)].AddNode(n);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> n;

            hashmap[hashFunction(n, 10)].Search(n);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> n;

            hashmap[hashFunction(n, 10)].Print();
            break;
        case 0:
            loop = false;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    
    return 0;
}