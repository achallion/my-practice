#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 4, 5, 7, 9, 12, 13, 16, 18};
    int n = sizeof(arr) / sizeof(int);

    int closest = -1;
    int t = 14;
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        int mid = s + e;
        mid >>= 1;
        int p1 = t - arr[s];
        int p2 = arr[e] - t;

        if (t == arr[mid])
        {
            closest = arr[mid];
            break;
        }
        if (p1 <= p2)
        {
            e = mid;
            closest = arr[s];
            continue;
        }
        if (p1 > p2)
        {
            if (s + 1 == e)
                s = mid + 1;
            else
                s = mid;
            closest = arr[e];
        }
    }
    cout << closest;
    int i = upper_bound(arr, arr + n, t) - arr;
    cout << min(t - arr[i - 1], arr[i] - t);
    return 0;
}