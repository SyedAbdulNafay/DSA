#include <iostream>
using namespace std;
#include <cstdlib>

struct Report
{
    int RollNo;
    float GP;
    Report * next;
};


void Push(Report ** top)
{
    Report * ptr = (Report *)malloc(sizeof(Report));

    cout << "Enter Roll Number: ";
    cin >> ptr->RollNo;
    cout << "Enter GP: ";
    cin >> ptr->GP;

    ptr->next = *top;
    *top = ptr;

    cout << "Pushed :) " << endl;
}

void Pop(Report ** top)
{
    if (*top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Report * temp = *top;
        *top = (*top)->next;
        cout << temp->RollNo << " is Popped :) " << endl;
        free(temp);
    }

}

int main()
{
    Report * top = NULL;

    bool flag = true;
    while (flag == true)
    {
        cout << "Press" << endl;
        cout << "1. To Push" << endl;
        cout << "2. To Pop" << endl;
        cout << "3. To Exit" << endl;
        int option;
        cin >> option;
        
        if (option == 1)
        {
            Push(&top);
        }
        else if (option == 2)
        {
            Pop(&top);
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