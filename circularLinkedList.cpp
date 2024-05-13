#include <iostream>
using namespace std;
#include <cstdlib>
#include <limits>

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
        index = i;
        next = NULL;
    }
};

void Insert(Report **head, int roll, float gp, int count)
{
    Report *node = new Report(roll, gp, count);
    if (*head == NULL)
    {
        node->next = node;
        *head = node;
        return;
    }
    Report *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->next = *head;
}

Report *RInsert(Report *head, Report *curr, int roll, float gp, int count)
{
    if (head == NULL)
    {
        Report *node = new Report(roll, gp, count);
        node->next = node;
        return node;
    }
    if (head->next == curr)
    {
        Report *node = new Report(roll, gp, count);
        node->next = curr;
        head->next = node;
        return head;
    }
    head->next = RInsert(head->next, curr, roll, gp, count);
    return head;
}

void Search(Report *head, int *nodeCount)
{
    if ((*nodeCount) == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        int input;
        cout << "Enter the roll number you want to search: ";
        cin >> input;

        Report *curr = head;
        bool flag = false;

        do
        {
            if (curr->RollNo == input)
            {
                cout << "Found at index: " << curr->index << endl;
                flag = true;
                break;
            }
            curr = curr->next;
        } while (curr->next != head);

        if (!flag)
        {
            cout << "Not found :(" << endl;
        }
    }
}

void Indexing(Report **head, int i)
{
    (*head)->index = i;
    if ((*head)->next == *head)
    {
        return;
    }
    Indexing(&((*head)->next), i + 1);
}

void Delete(Report **head, int value)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if ((*head)->RollNo == value)
    {
        Report *temp = *head;
        if ((*head)->next == *head)
        {
            Report *toDelete = *head;
            *head = NULL;
            delete toDelete;
            return;
        }
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        Report *toDelete = *head;
        temp->next = (*head)->next;
        *head = (*head)->next;
        delete toDelete;
        return;
    }
    Report *temp = (*head)->next;

    while (temp != *head)
    {
        if (temp->next->RollNo == value)
        {
            Report *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }

        temp = temp->next;
    }
    cout << "Not found" << endl;
}

void DeleteAll(Report **head, int *nodeCount)
{
    if ((*nodeCount) == 0)
    {
        cout << "List is already empty" << endl;
    }
    else
    {
        Report *curr = *head;
        Report *temp;

        do
        {
            temp = curr;
            curr = curr->next;
            free(temp);
            (*nodeCount)--;
        } while (curr != *head);

        *head = NULL;
        cout << "List is deleted" << endl;
    }
}

void Print(Report *head, int *nodeCount)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Report *temp = head;
    do
    {
        cout << "Roll Number: " << temp->RollNo << ", GP: " << temp->GP << endl;
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void itemCount(int *nodeCount)
{
    cout << "Number of items in the list are: " << (*nodeCount) << endl;
}

int main()
{
    Report *head = NULL;
    int nodeCount = 0;
    bool loop = true;

    while (loop)
    {
        cout << "Which operation do you want to proceed with? " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Delete All" << endl;
        cout << "6. Number of items" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;
        if (option == 0)
        {
            loop = false;
        }
        else if (option == 1)
        {
            cout << "Roll Number: ";
            int roll;
            cin >> roll;
            cout << "GP: ";
            int gp;
            cin >> gp;
            Insert(&head, roll, gp, nodeCount);

            // head = Insert(head, head, roll, gp, nodeCount);
            // nodeCount++;
        }
        else if (option == 2)
        {
            Search(head, &nodeCount);
        }
        else if (option == 3)
        {
            Print(head, &nodeCount);
        }
        else if (option == 4)
        {
            cout << "Roll Number: ";
            int roll;
            cin >> roll;
            Delete(&head, roll);
            cout << "Deleted" << endl;
            nodeCount--;
        }
        else if (option == 5)
        {
            DeleteAll(&head, &nodeCount);
        }
        else if (option == 6)
        {
            itemCount(&nodeCount);
        }
        else
        {
            cout << "Enter valid input" << endl;
        }
    }

    // cout << "Do you want to continue? y/n: " << endl;
    // string answer;
    // cin >> answer;

    // while (answer == "y")
    // {
    //     cout << "Which operation do you want to proceed with? " << endl;
    //     cout << "1. Insert" << endl;
    //     cout << "2. Search" << endl;
    //     cout << "3. Print" << endl;
    //     cout << "4. Delete" << endl;
    //     cout << "5. Delete All" << endl;
    //     cout << "6. Number of items" << endl;

    //     int option;
    //     cin >> option;

    //     if (option == 1)
    //     {
    //         cout << "Roll Number: ";
    //         int roll;
    //         cin >> roll;
    //         cout << "GP: ";
    //         int gp;
    //         cin >> gp;
    //         Insert(&head, roll, gp, nodeCount);
    //         // cout << "Roll Number: ";
    //         // int roll;
    //         // cin >> roll;
    //         // cout << "GP: ";
    //         // int gp;
    //         // cin >> gp;

    //         // head = Insert(head, head, roll, gp, nodeCount);
    //         // nodeCount++;
    //     }
    //     else if (option == 2)
    //     {
    //         Search(head, &nodeCount);
    //     }
    //     else if (option == 3)
    //     {
    //         Print(head, &nodeCount);
    //     }
    //     else if (option == 4)
    //     {
    //         cout << "Roll Number: ";
    //         int roll;
    //         cin >> roll;
    //         Delete(&head, roll);
    //         Indexing(&head, 0);
    //         nodeCount--;
    //     }
    //     else if (option == 5)
    //     {
    //         DeleteAll(&head, &nodeCount);
    //     }
    //     else if (option == 6)
    //     {
    //         itemCount(&nodeCount);
    //     }
    //     else
    //     {
    //         cout << "Enter valid input" << endl;
    //     }

    //     cout << "Do you want to continue? y/n: " << endl;
    //     cin >> answer;
    // }

    return 0;
}