#include <iostream>
using namespace std;
#include <cstdlib>


struct Report
{
    int RollNo;
    float GP;
    Report * next;
    int index;
};

void Insert(Report **head, int * nodeCount)
{
    Report * ptr = (Report *)malloc(sizeof(Report));
    cout << "Enter your roll number: ";
    cin >> ptr->RollNo;
    cout << "Enter your GP: ";
    cin >> ptr->GP;

    ptr->next = NULL;
    ptr->index = *nodeCount;

    if (*head == NULL)
    {
        *head = ptr;
    } 
    else
    {
        Report * curr = *head;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = ptr;
    }
    (*nodeCount)++;
}

void SortedInsert(Report **head, int * nodeCount)
{
    Report * ptr = (Report *)malloc(sizeof(Report));
    cout << "Enter your roll number: ";
    cin >> ptr->RollNo;
    cout << "Enter your GP: ";
    cin >> ptr->GP;

    ptr->next = NULL;
    ptr->index = *nodeCount;

    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        // int toSort = ptr->RollNo;
        Report * curr = *head;
        Report * prev = NULL;

        while (ptr->RollNo > curr->RollNo)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = ptr;
        ptr->next = curr;
    }
    (*nodeCount)++;
}

void Search(Report * head, int * nodeCount)
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

        Report * curr = head;
        bool flag = false;

        while (curr != NULL)
        {
            if (curr->RollNo == input)
            {
                cout << "Found at index: " << curr->index << endl;
                flag = true;
                break;
            }
            curr = curr->next;
        }
        if (!flag)
        {
            cout << "Not found :(" << endl;
        }
    }
}

void Delete(Report **head, int * nodeCount)
{
    if ((*nodeCount) == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Report * curr = *head;

        int toDel;
        cout << "Enter the roll number you want to delete: ";
        cin >> toDel;


        if ((*head)->RollNo == toDel)
        {
            *head = (*head)->next;
            free(curr);
        }
        else
        {
            Report * prev = *head;
            curr = (*head)->next;
            while (curr != NULL)
            {
                if (curr->RollNo == toDel)
                {
                    prev->next = curr->next;
                    free(curr);
                    Report * temp = prev->next;
                    while (temp != NULL)
                    {
                        temp->index--;
                        temp = temp->next;
                    }
                    return;
                }
                curr = curr->next;
                prev = prev->next;
            }
            cout << "Not found in list" << endl;
        }
        (*nodeCount)--;
    }
}

void DeleteAll(Report **head, int * nodeCount)
{
    if ((*nodeCount) == 0)
    {
        cout << "List is already empty" << endl;
    }
    else
    {
        Report *curr = *head;
        while (curr != NULL)
        {
            *head = curr->next;
            free(curr);
            curr = *head;
        }
        (*nodeCount) = 0;
    }
}

void Print(Report * head, int * nodeCount)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        Report * curr = head;

        while (curr != NULL)
        {
            cout << curr->index << ". " "Roll No: " << curr->RollNo << ", GP: " << curr->GP << endl;
            curr = curr->next;
        }
    }
}

void itemCount(int * nodeCount)
{
    cout << "Number of items in the list are: " << (*nodeCount) << endl;
}

int main()
{
    Report * head = NULL;
    int (nodeCount) = 0;

    cout << "Which operation do you want to proceed with? " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Print" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Delete All" << endl;
    cout << "6. Number of items" << endl;
    cout << "7. Sorted Insert" << endl;

    int option;
    cin >> option;

    if (option == 1)
    {
        Insert(&head, &nodeCount);
    }
    else if (option == 2)
    {
        Search(head, &nodeCount);
    }
    else if (option == 3)
    {
        Print(head, &nodeCount);
    } else if (option == 4)
    {
        Delete(&head, &nodeCount);
    }
    else if (option == 5)
    {
        DeleteAll(&head, &nodeCount);
    }
    else if (option == 6)
    {
        itemCount(&nodeCount);
    }
    else if(option == 7)
    {
        SortedInsert(&head, &nodeCount);
    }
    else 
    {
        cout << "Enter valid input" << endl;
    }

    cout << "Do you want to continue? y/n: " << endl;
    string answer;
    cin >> answer;

    while (answer == "y")
    {
        cout << "Which operation do you want to proceed with? " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Delete All" << endl;
        cout << "6. Number of items" << endl;
        cout << "7. Sorted Insert" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            Insert(&head, &nodeCount);
        }
        else if (option == 2)
        {
            Search(head, &nodeCount);
        }
        else if (option == 3)
        {
            Print(head, &nodeCount);
        } else if (option == 4)
        {
            Delete(&head, &nodeCount);
        }
        else if (option == 5)
        {
            DeleteAll(&head, &nodeCount);
        }
        else if (option == 6)
        {
            itemCount(&nodeCount);
        }
        else if (option == 7)
        {
            SortedInsert(&head, &nodeCount);
        }
        else 
        {
            cout << "Enter valid input" << endl;
        }

        cout << "Do you want to continue? y/n: " << endl;
        cin >> answer;
    }

    return 0;
}