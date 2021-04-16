#include <iostream>

using namespace std;

int main()
{
    int arr[] = {5, 7, 2, 1, 4, 3};
    int n = 6;
    int sum = n + 1;
    for (int i = 0; i < n; i++)
    {
        sum ^= ((i + 1) ^ arr[i]);
    }
    cout << sum;
    return 0;
}