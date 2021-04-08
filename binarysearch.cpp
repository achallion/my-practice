#include <iostream>

using namespace std;

int fi(int arr[], int n, int ele)
{
    int s = 0;
    int e = n - 1;
    int pos;
    while (s <= e)
    {
        int mid = s + e;
        mid /= 2;
        if (arr[mid] == ele)
        {
            pos = mid;
            e = mid - 1;
        }
        else if (arr[mid] < ele)
            s = mid + 1;
        else if (arr[mid] > ele)
            e = mid - 1;
    }
    return pos;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    cout << fi(arr, n, 3);
    return 0;
}