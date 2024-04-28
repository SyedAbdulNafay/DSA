#include <iostream>
using namespace std;

void MaxHeapify(int array[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
    {
        largest = l;
    }
    if (r < size && array[r] > array[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(array[i], array[largest]);
        MaxHeapify(array, size, largest);
    }
}

void MinHeapify(int array[], int size, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] < array[smallest])
    {
        smallest = l;
    }
    if (r < size && array[r] < array[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(array[i], array[smallest]);
        MinHeapify(array, size, smallest);
    }
}

void buildMaxHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        MaxHeapify(array, size, i);
    }
}

void buildMinHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        MinHeapify(array, size, i);
    }
}

void heapSort(int array[], int size)
{
    buildMinHeap(array, size);

    for (int i = size - 1; i >= 1; i--)
    {
        swap(array[0], array[i]);
        MinHeapify(array, i, 0);
    }
}

int main()
{
    int arr[8] = {5, 12, 64, 1, 37, 90, 91, 97};
    int size = sizeof(arr) / sizeof(arr[0]);
    int lc = arr[8];
    bool loop = true;
    while (loop)
    {
        cout << "1. Max Heap" << endl;
        cout << "2. Min Heap" << endl;
        cout << "3. Heap Sort" << endl;
        cout << "4. Print" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            buildMaxHeap(arr, size);
            break;

        case 2:
            buildMinHeap(arr, size);
            break;

        case 3:
            heapSort(arr, size);
            break;

        case 4:
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 0:
            loop = false;
            break;

        default:
            break;
        }
    }
    return 0;
}