#include <iostream>
using namespace std;

void Insert(int arr[100], int value, int *size)
{
    cout << "Inserting " << value << endl;
    cout << "Size: " << *size << endl;
    int index = (*size);
    cout << "Inserted at index " << index << endl;
    arr[index] = value;

    while (index > 0)
    {
        int parent = index / 2;
        cout << "Comparing with parent " << parent << endl;
        if (arr[parent] < arr[index])
        {
            cout << "Swapping " << arr[parent] << " & " << arr[index] << endl;
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
        {
            return;
        }
    }
    (*size)++;
    cout << "Size updated to " << *size << endl;
}

void Print(int arr[100], int size)
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100];
    // arr[0] = -1;
    int size = 0;
    
    Insert(arr, 50, &size);
    Insert(arr, 55, &size);
    Insert(arr, 53, &size);
    Insert(arr, 52, &size);
    Insert(arr, 54, &size);
    Print(arr, size);
    return 0;
}