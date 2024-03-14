#include <iostream>
using namespace std;

void LinearProbing(int hashtable[10], int size, int index, int og_index, int key)
{
    bool flag = true;
    while (hashtable[index] != -1)
    {
        index++;

        if (index >= size)
        {
            index = index % size;
        }

        if (index == og_index)
        {
            flag = false;
            cout << "No space available" << endl;
            break;
        }
    }
    
    if (flag == true)
    {
        hashtable[index] = key;
        cout << "Inserted" << endl;
    }
}

bool QuadraticProbing(int hashtable[10], int size, int * index, int og_index, int key)
{
    int i = 1;
    bool flag = true;
    while (hashtable[*index] != -1)
    {
        *index = og_index + (i*i);
        i++;

        if (*index >= size)
        {
            *index = *index % size;
        }
        
        if (i >= size)
        {
            flag = false;
            break;
        }
        
    }
    
    if (flag == true)
    {
        hashtable[*index] = key;
        cout << "Inserted" << endl;
    }
    
    return flag;
}

void Insert(int hashtable[10], int size)
{
    cout << "Enter number: ";
    int key;
    cin >> key;

    int index = key % size;
    int og_index = index;

    bool check = QuadraticProbing(hashtable, size, &index, og_index, key);

    if (check == false)
    {
        cout << "Entered linear probing" << endl;
        LinearProbing(hashtable, size, index, index, key);
    }
    
}

void Print(int hashtable[10], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i < size-1)
        {
            cout << hashtable[i] << " ";
        }
        else
        {
            cout << hashtable[i] << endl;
        }
    }
}

bool QuadraticSearch(int hashtable[10], int size, int * index, int og_index, int key)
{
    int i = 1;
    bool flag = false;

    while (i < size)
    {
        if (hashtable[*index] == key)
        {
            cout << "Found at index " << *index << endl;
            flag = true;
            break;
        }
        *index = og_index + (i*i);
        i++;
        if (*index >= size)
        {
            *index = *index % size;
        }
    }
    
    return flag;
}

void LinearSearching(int hashtable[10], int size, int index, int og_index, int key)
{
    bool flag = false;
    
    do
    {
        if (hashtable[index] == key)
        {
            cout << "Found at index " << index << endl;
            flag = true;
            break;
        }
        
        index++;

        if (index >= size)
        {
            index = index % size;
        }
        
    } while (index != og_index);
    
    if (flag == false)
    {
        cout << "Not found" << endl;
    }
    
}

void Search(int hashtable[10], int size)
{
    cout << "Enter value: ";
    int key;
    cin >> key;

    int index = key % size;
    int og_index = index;

    bool check = QuadraticSearch(hashtable, size, &index, og_index, key);

    if (check == false)
    {
        LinearSearching(hashtable, size, index, index, key);
    }
    
}

int main()
{
    int hashtable[10];

    int size = sizeof(hashtable)/sizeof(hashtable[0]);

    for (int i = 0; i < size; i++)
    {
        hashtable[i] = -1;
    }

    bool loop = true;
    while (loop == true)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "0. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            Insert(hashtable, size);
            break;
        case 2:
            Search(hashtable, size);
            break;
        case 3:
            Print(hashtable, size);
            break;
        case 0:
            loop = false;
            break;
        default:
            cout << "Invalid entry" << endl;
            break;
        }
    }
    
    return 0;
}