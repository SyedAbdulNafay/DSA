#include <iostream>
using namespace std;
#include <cstdlib>

struct Report
{
    int RollNo;
    float GP;
    Report * next;
};

void EnQueue(Report ** front, Report ** rear)
{
    Report * ptr = (Report *)malloc(sizeof(Report));

    cout << "Enter Roll Number: ";
    cin >> ptr->RollNo;
    cout << "Enter GP: ";
    cin >> ptr->GP;

    ptr->next = NULL;

    if (*front == NULL)
    {
        *front = ptr;
        *rear = ptr;
    }
    else
    {
        (*rear)->next = ptr;
        *rear = (*rear)->next;
    }
}

void DeQueue(Report ** front)
{
    if (*front == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Report * temp = *front;
        *front = (*front)->next;
        cout << temp->RollNo << " is DeQueued. " << endl;
        free(temp);
    }
}

int main()
{
    Report * front = NULL;
    Report * rear = NULL;

    bool flag = true;
    while (flag == true)
    {
        cout << "Press" << endl;
        cout << "1. To EnQueue" << endl;
        cout << "2. To DeQueue" << endl;
        cout << "3. To Exit" << endl;
        int option;
        cin >> option;
        
        if (option == 1)
        {
            EnQueue(&front, &rear);
        }
        else if (option == 2)
        {
            DeQueue(&front);
        }
        else if (option == 3)
        {
            flag = false;
        }
        else
        {
            cout << "Enter valid option. " << endl;
        }
    }

    return 0;
}