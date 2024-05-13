#include <iostream>
using namespace std;

void LinearProbing(int arr[5], int length, int value, int index, int og_index)
{
    bool flag = true;
    while (arr[index] != -1)
    {
        index++;
        if (index >= length)
        {
            index = 0;
        }
        if (index == og_index)
        {
            cout << "No space available" << endl;
            flag = false;
            break;
        }
    }

    if (flag)
    {
        arr[index] = value;
        cout << "Inserted" << endl;
    }
}

bool QuadraticProbing(int arr[5], int length, int value, int *index, int og_index)
{
    int i = 1;
    bool flag = true;

    while (arr[*index] != -1)
    {
        *index = og_index + (i * i);
        i++;
        if (*index >= length)
        {
            *index = *index % length;
        }

        if (*index == og_index)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        arr[*index] = value;
        cout << "Inserted" << endl;
    }

    return flag;
}

void Insert(int arr[5], int length, int value)
{
    int og_index = value % length;
    int index = og_index;

    bool check = QuadraticProbing(arr, length, value, &index, og_index);

    if (!check)
    {
        LinearProbing(arr, length, value, index, index);
    }
}

void Print(int arr[5], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void LinearSearching(int arr[5], int length, int value, int index, int og_index)
{
    bool flag = true;

    while (arr[index] != value)
    {
        index++;
        if (index >= length)
        {
            index = 0;
        }
        if (index == og_index)
        {
            cout << "Not found" << endl;
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "Found at index " << index << endl;
    }
}

bool QuadraticSearching(int arr[5], int length, int value, int *index, int og_index)
{
    int i = 1;
    bool flag = true;

    while (arr[*index] != value)
    {
        *index = og_index + (i * i);
        i++;

        if (*index >= length)
        {
            *index = *index % length;
        }
        if (*index == og_index)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "Found at index " << *index << endl;
    }
    return flag;
}

void Search(int arr[5], int length, int value)
{
    int og_index = value % length;
    int index = og_index;

    int check = QuadraticSearching(arr, length, value, &index, og_index);

    if (!check)
    {
        LinearSearching(arr, length, value, index, index);
    }
}

int main()
{
    int arr[5] = {-1, -1, -1, -1, -1};
    int length = sizeof(arr) / sizeof(arr[0]);

    while (true)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            Insert(arr, length, value);
        }
        else if (option == 2)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            Search(arr, length, value);
        }
        else if (option == 3)
        {
            Print(arr, length);
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