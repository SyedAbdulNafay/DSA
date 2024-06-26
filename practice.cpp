#include <iostream>
using namespace std;
#include <queue>

void PrintArr(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Insert(int arr[100], int value, int *size)
{
    int index = (*size);
    arr[index] = value;

    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
    (*size)++;
}

void DeleteFromHeap(int arr[100], int *size)
{
    if (*size == 0)
    {
        cout << "Empty" << endl;
        return;
    }
    arr[0] = arr[(*size) - 1];
    (*size)--;

    int i = 0;
    while (i < *size)
    {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (leftIndex < *size && arr[i] < arr[leftIndex])
        {
            swap(arr[i], arr[leftIndex]);
            i = leftIndex;
        }
        else if (rightIndex < *size && arr[i] < arr[rightIndex])
        {
            swap(arr[i], arr[rightIndex]);
            i = rightIndex;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int arr[100];
    int size = 0;

    while (true)
    {
        cout << "Press" << endl;
        cout << "1. Insert into array" << endl;
        cout << "2. Delete from array" << endl;
        cout << "3. Print array" << endl;
        cout << "0. Exit" << endl;

        int opt;
        cin >> opt;

        if (opt == 1)
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            Insert(arr, value, &size);
        }
        else if (opt == 2)
        {
            DeleteFromHeap(arr, &size);
        }
        else if (opt == 3)
        {
            PrintArr(arr, size);
        }
        else if (opt == 0)
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