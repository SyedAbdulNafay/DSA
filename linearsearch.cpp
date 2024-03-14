#include <iostream>

int main()
{
    int arr[10] = {11,32,44,22,78,91,12,36,50,27};
    int number;

    std::cout << "Enter the number you want to search: ";

    std::cin >> number;

    int length = sizeof(arr)/sizeof(arr[0]);
    //linear search
    int flag = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == number)
        {
            std::cout << number << " found at index " << i << std::endl;
            flag++;
             break;
        }
        
    }

    if (flag == 0)
    {
        std::cout << number << " was not found in this array";
    }

    return 0;
    
}