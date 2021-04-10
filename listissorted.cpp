#include <iostream>
#include <list>

using namespace std;

bool issorted(const list<int> &l)
{
    if (l.size() <= 1)
        return true;

    list<int>::const_iterator ptr = l.begin();
    while (true)
    {
        int p = *ptr;
        ptr++;
        if (ptr == l.end())
            break;
        int n = *ptr;
        if (p > n)
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    list<int> l;
    for (int i = 0; i < n; i++)
        l.push_back(arr[i]);
    cout << (issorted(l) == 1 ? "true" : "false");
    return 0;
}