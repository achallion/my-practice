#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void cyclicsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            swap(arr[i], arr[arr[i] - 1]);
            i--;
        }
    }
}

int main()
{
    int arr[] = {6, 2, 4, 1, 3, 5};
    int n = 6;
    cyclicsort(arr, n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}