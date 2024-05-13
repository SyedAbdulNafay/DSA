#include <iostream>
using namespace std;
#include <cstdlib>

struct Report
{
    int RollNo;
    float GP;
    Report *next;
    Report *prev;
    int index;

    Report(int r, float g, int i)
    {
        RollNo = r;
        GP = g;
        next = NULL;
        prev = NULL;
        index = i;
    }
};

Report *RInsert(Report *head, int roll, float gp, int count)
{
    if (head == NULL)
    {
        Report *node = new Report(roll, gp, count);
        return node;
    }
    head->next = RInsert(head->next, roll, gp, count);
    head->next->prev = head;
    return head;
}

bool Search(Report *head, int value)
{
    if (head == NULL)
        return false;
    if (value == head->RollNo)
    {
        cout << "Found at index " << head->index << endl;
        return true;
    }
    return Search(head->next, value);
}

void Print(Report *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << "Roll Number: " << head->RollNo << ", GP: " << head->GP << ", index: " << head->index << endl;
    Print(head->next);
}

void Indexing(Report **head, int i)
{
    if (*head == NULL)
        return;
    (*head)->index = i;
    Indexing(&((*head)->next), i + 1);
}

Report *Delete(Report *head, int value)
{
    if (head == NULL)
    {
        cout << "Not found" << endl;
        return head;
    }
    if (head->RollNo == value)
    {
        Report *temp = head->next;
        head->next->prev = head->prev;
        Indexing(&temp, head->index);
        delete head;
        return temp;
    }
    head->next = Delete(head->next, value);
    return head;
}

void DeleteAll(Report *head)
{
    if (head == NULL)
        return;
    DeleteAll(head->next);
    delete head;
}

void ItemCount(int *nodeCount)
{
    cout << "The number of nodes in the list: " << (*nodeCount) << endl;
}

int main()
{
    Report *head = NULL;
    int nodeCount = 0;
    bool loop = true;

    while (loop)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Delete All" << endl;
        cout << "6. Number of items" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 0:
            loop = false;
            break;

        case 1:
            cout << "roll number: ";
            int roll;
            cin >> roll;
            cout << "GP: ";
            float gp;
            cin >> gp;

            head = RInsert(head, roll, gp, nodeCount);
            nodeCount++;
            break;

        case 2:
            if (head == NULL)
            {
                cout << "Linked List is empty" << endl;
            }
            else
            {
                cout << "Enter value: ";
                int value;
                cin >> value;
                bool check = Search(head, value);
                if (!check)
                {
                    cout << "Not found" << endl;
                }
            }
            break;

        case 3:
            Print(head);
            break;

        case 4:
            if (head == NULL)
            {
                cout << "Linked List is empty" << endl;
            }
            else
            {
                cout << "Enter roll number: ";
                int value;
                cin >> value;
                head = Delete(head, value);
                nodeCount--;
            }
            break;

        case 5:
            if (head == NULL)
            {
                cout << "Linked List is empty" << endl;
            }
            else
            {
                DeleteAll(head);
                head = NULL;
                nodeCount = 0;
            }
            break;

        case 6:
            cout << "Item Count: " << nodeCount << endl;
            break;

        default:
            break;
        }
    }

    return 0;
}