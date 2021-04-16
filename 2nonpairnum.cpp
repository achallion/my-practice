#include <iostream>

using namespace std;

void find2nos(int *arr, int n)
{
    int xorr = 0;
    for (int i = 0; i < n; i++)
        xorr ^= arr[i];

    int mask = xorr & -xorr;
    int a0 = 0, a1 = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] & mask)
            a1 ^= arr[i];
        else
            a0 ^= arr[i];

    cout << "Nos are : " << a0 << " " << a1;
}

int main()
{
    int arr[] = {3, 2, 6, 8, 3, 5, 7, 8, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    find2nos(arr, n);

    return 0;
}