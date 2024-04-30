#include <iostream>
using namespace std;
#include <cstdlib>

struct Report
{
    int RollNo;
    float GP;
    Report *next;
    int index;

    Report(int r, float g, int i)
    {
        RollNo = r;
        GP = g;
        next = NULL;
        index = i;
    }
};

Report *RInsert(Report *head, int roll, float gp, int count)
{
    if (head == NULL)
    {
        Report *node = new Report(roll, gp, count);
        head = node;
        return head;
    }
    head->next = RInsert(head->next, roll, gp, count);
    return head;
}

void Indexing(Report **head, int i)
{
    if (*head == NULL)
        return;
    (*head)->index = i;
    Indexing(&((*head)->next), i+1);
}

Report *SortedInsert(Report *head, int roll, float gp, int count)
{
    if (head == NULL)
    {
        Report *node = new Report(roll, gp, count);
        return node;
    }
    if (roll < head->RollNo)
    {
        Report *node = new Report(roll, gp, count);
        node->next = head;
        head = node;
    }
    else
    {
        head->next = SortedInsert(head->next, roll, gp, count);
    }
    return head;
}

bool Search(Report *head, int value)
{
    if (head == NULL)
        false;
    if (value == head->RollNo)
    {
        cout << "Found at index " << head->index << endl;
        return true;
    }
    return Search(head->next, value);
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

void Print(Report *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << "Roll Number: " << head->RollNo << ", GP: " << head->GP << endl;
    Print(head->next);
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
        cout << "7. Sorted Insert" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            cout << "Enter Roll Number: ";
            int roll;
            cin >> roll;
            cout << "Enter GP: ";
            float gp;
            cin >> gp;
            head = RInsert(head, roll, gp, nodeCount);
            nodeCount++;
        }
        else if (option == 2)
        {
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
        }
        else if (option == 3)
        {
            if (head == NULL)
            {
                cout << "Linked List is empty" << endl;
            }
            else
            {
                Print(head);
            }
        }
        else if (option == 4)
        {
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
        }
        else if (option == 5)
        {
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
        }
        else if (option == 6)
        {
            cout << "Item Count: " << nodeCount << endl;
        }
        else if (option == 7)
        {
            cout << "Enter Roll Number: ";
            int roll;
            cin >> roll;
            cout << "Enter GP: ";
            float gp;
            cin >> gp;
            head = SortedInsert(head, roll, gp, nodeCount);
            nodeCount++;
            Indexing(&head, 0);
        }
        else if (option == 0)
        {
            loop = false;
        }
        else
        {
            cout << "Enter valid input" << endl;
        }
    }
    return 0;
}