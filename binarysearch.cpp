#include <iostream>

int main()
{
    int arr[10] = {1,4,9,16,25,36,49,64,81,100};
    int number;

    std::cout << "Enter the number you want to search: ";

    std::cin >> number;

    int flag = 0;

    int length = sizeof(arr)/sizeof(arr[0]);

    int L = 0;
    int R = length-1;
    

    while (L<=R)
    {
        int M = (L+R)/2;
        if (arr[M] == number)
        {
            std::cout << number << " found at index " << M;
            flag++;
            return 0;
        } else if (number > arr[M])
        {
            L = M+1;
        } else
        {
            R = M-1;
        } 
    }

    if (flag==0)
    {
        std::cout << "Not found in this array";
    }
    
    return 0;
}