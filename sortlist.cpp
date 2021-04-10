#include <iostream>
#include <list>

using namespace std;
#define lici list<int>::const_iterator

list<int> merge(const list<int> &l1, const list<int> &l2)
{
    list<int> l;
    list<int>::const_iterator s1 = l1.begin(), s2 = l2.begin(), e1 = l1.end(), e2 = l2.end();
    while (s1 != e1 && s2 != e2)
    {
        if (*s1 < *s2)
            l.push_back(*s1++);
        else
            l.push_back(*s2++);
    }

    while (s1 != e1)
        l.push_back(*s1++);

    while (s2 != e2)
        l.push_back(*s2++);

    return l;
}

list<int> mergesort(const list<int> &l, lici s, lici e)
{
    if (s == prev(e))
    {
        list<int> ans;
        ans.push_back(*s);
        return ans;
    }
    lici ptrs = s, ptrf = s;
    while (ptrf != e && next(ptrf) != e)
    {
        ptrs++;
        ptrf++;
        ptrf++;
    }
    list<int>
        l1 = mergesort(l, s, ptrs);
    list<int> l2 = mergesort(l, ptrs, e);
    return merge(l1, l2);
}

list<int> sort(const list<int> &l)
{
    if (l.size() <= 1)
        return l;

    lici s, e;
    s = l.begin();
    e = l.end();
    return mergesort(l, s, e);
}

int arr[] = {6, 3, 6, 78, 34, 23, 123, 67, 32, 12, 72, 4};
int n = sizeof(arr) / sizeof(int);

int main()
{
    list<int> l(arr, arr + n);
    l = sort(l);
    for (int x : l)
        cout << x << " ";
    cout << "\n";
    return 0;
}