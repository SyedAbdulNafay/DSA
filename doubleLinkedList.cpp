#include <iostream>
using namespace std;
#include <cstdlib>

struct Report
{
    int RollNo;
    float GP;
    Report * next;
    Report * prev;
    int index;
};

void Insert(Report **head, int * nodeCount)
{
    Report * ptr = (Report *)malloc(sizeof(Report));
    cout << "Enter roll number: ";
    cin >> ptr->RollNo;
    cout << "Enter GP: ";
    cin >> ptr->GP;

    ptr->next = NULL;
    ptr->prev = NULL;
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
        ptr->prev = curr;
    }
    (*nodeCount)++;
}

void Search(Report * head, int * nodeCount)
{
    if (*nodeCount == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        int input;
        cout << "Enter the roll number you want to search: ";
        cin >> input;
        bool flag = false;

        Report * curr = head;
        
        while (curr != NULL)
        {
            if (curr->RollNo == input)
            {
                cout << "Found at index " << curr->index << endl;
                flag = true;
                break;
            }
            curr = curr->next;
        }
        if (!flag)
        {
            cout << "Not found" << endl;
        }
    }
}

void Print(Report * head, int * nodeCount)
{
    if (*nodeCount == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Report * curr = head;

        while (curr != NULL)
        {
            cout << curr->index << ". Roll No: " << curr->RollNo << ", GP: " << curr->GP << endl;
            curr = curr->next;
        }
    }
}

void Delete(Report **head, int * nodeCount)
{
    if (nodeCount == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Report * curr = *head;
        cout << "Enter the roll number you want to delete: ";
        int toDel;
        cin >> toDel;

        if (toDel == (*head)->RollNo)
        {
            *head = (*head)->next;
            (*head)->prev = NULL;
            free(curr);
        }
        else
        {
            curr = (*head)->next;
            bool flag = false;
            while (curr != NULL)
            {
                if (curr->RollNo == toDel)
                {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;

                    Report * temp = curr->next;
                    while (temp != NULL)
                    {
                        temp->index--;
                        temp = temp->next;
                    }
                    flag = true;
                    free(curr);
                    break;
                }
                curr = curr->next;
            }
            if (!flag)
            {
                cout << "Not found" << endl;
            }
        }   
        (*nodeCount)--;   
    }
}

void DeleteAll(Report **head, int * nodeCount)
{
    if ((*nodeCount == 0))
    {
        cout << "List is already empty" << endl;
    }
    else
    {
        Report * curr = *head;

        while (curr != NULL)
        {
            *head = (*head)->next;
            free(curr);
            curr = *head;
        }
        (*nodeCount) == 0;
        cout << "Deleted" << endl;
    }
}

void ItemCount(int * nodeCount)
{
    cout << "The number of nodes in the list: " << (*nodeCount) << endl;
}

int main()
{
    Report * head = NULL;
    int nodeCount = 0;

    cout << "Which operation do you want to proceed with? " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Print" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Delete All" << endl;
    cout << "6. Number of items" << endl;

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
        ItemCount(&nodeCount);
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
            ItemCount(&nodeCount);
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