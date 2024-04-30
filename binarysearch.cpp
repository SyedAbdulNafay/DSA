#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    int number;

    bool loop = true;

    while (loop)
    {
        cout << "Enter the number you want to search: ";

        cin >> number;

        bool flag = false;

        int length = sizeof(arr) / sizeof(arr[0]);

        int L = 0;
        int R = length - 1;

        while (L <= R)
        {
            int M = (L + R) / 2;
            if (arr[M] == number)
            {
                cout << number << " found at index: " << M << endl;
                flag = true;
                break;
            }
            else if (number > arr[M])
            {
                L = M + 1;
            }
            else
            {
                R = M - 1;
            }
        }

        if (!flag)
        {
            cout << "Not found in this array" << endl;
        }
        cout << "Press 0 to exit" << endl;
        int option;
        cin >> option;

        if (option == 0)
        {
            loop = false;
        }
    }

    return 0;
}