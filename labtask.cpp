#include <iostream>
using namespace std;

void selectionSort(int arr[], int length){
    for (int j = 0; j<length-1; j++){
        int m_i = j;
        for (int i = j+1; i < length; i++)
        {
            if (arr[i] < arr[m_i])
            {
                // swapping
                int t = arr[m_i];
                arr[m_i] = arr[i];
                arr[i] = t;
            }
            
        }
    }
}

void bubbleSort(int arr[], int length){
    for (int j = 0; j < length-1; j++)
    {
        for (int i = 0; i < length - j -1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
            }
            
        }
        
    }
}

void insertionSort(int arr[], int length){
    // for (int j = 1; j < length; j++)
    // {   int i = j;
    //     int hold = arr[i];
    //     while (i>=0 && hold < arr[i-1])
    //     {
    //         arr[i] = arr[i-1];
    //         i--;
    //     }
    // }
    
    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (j>0 && arr[j-1]<arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        
    }
    
}

int main(){
    int length;
    cout << "Enter the length of your list: ";
    cin >> length;
    int arr[length];

    for (int i = 0; i < length; i++)
    {
        cout << "Enter an element: ";
        cin >> arr[i];
    }
    
    int choice;
    cout << "Which sort algorithm would you want?" << endl;
    cout << "Press 1 for selection sort" << endl << "Press 2 for bubble sort" << endl << "Press 3 for insertion sort" << endl;
    cin >> choice;

    if (choice == 1)
    {
        selectionSort(arr, length);
        cout << "Your ordered list: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << endl;
        }
    } else if (choice == 2)
    {
        bubbleSort(arr, length);
        cout << "Your ordered list: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << endl;
        }
    } else if (choice == 3){
        insertionSort(arr, length);
        cout << "your ordered list: " << endl;
        for (int i = length-1; i > -1; i--)
        {
            cout << arr[i] << endl;
        }
        
    }
    
    
}


