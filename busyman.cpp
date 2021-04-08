#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> p[6] = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};

bool endtime(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    return false;
}

int main()
{
    int n = 6;
    sort(p, p + n, endtime);
    vector<pair<int, int>> v;
    int timemax, t;
    int i = 0;
    t = 0;
    timemax = p[n - 1].second;
    while (i < n)
    {
        t = p[i].second;
        cout << "From " << p[i].first << " to " << p[i].second << " -> " << i << "\n";
        // search for next i at next smallest end time
        int k = i + 1;

        while (k < n)
        {
            if (p[k].first >= p[i].second)
            {
                break;
            }
            k++;
        }
        i = k;
    }
    return 0;
}