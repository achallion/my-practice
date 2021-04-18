#include <iostream>

using namespace std;

int main()
{
    int arr[] = {8, 3, 5, 2, 4, 6, 0, 1};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    int maxsum = sum;

    for (int i = 0; i < n - k; i++)
    {
        sum += (arr[i + k] - arr[i]);
        maxsum = max(maxsum, sum);
    }

    cout << maxsum;

    return 0;
}