#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
bitset<N> bit;

int maxno(int n, int k, int s)
{
    int firsttime = 0;
    int maxno = s;
    int gnbmask = 1 << (n - 1);
    int rnbmask = ~gnbmask;
    for (int i = 0; i < n; i++)
    {
        int nthbit = (gnbmask & s) > 0 ? 1 : 0;
        s &= rnbmask;
        s <<= 1;
        s += nthbit;
        if (s > maxno)
        {
            maxno = s;
            firsttime = i + 1;
        }
    }
    int count = 0;
    int countofmax = 0;
    for (int i = 0; i <= n; i++)
    {
        if (countofmax == k)
        {
            return count;
        }
        if (i == n)
        {
            i = 0;
            continue;
        }
        //
        int nthbit = (gnbmask & s) > 0 ? 1 : 0;
        s &= rnbmask;
        s <<= 1;
        s += nthbit;

        //
        if (s == maxno)
            countofmax++;
        count++;
    }
    return -1;
}

int convtoint(string s)
{
    bit.reset();
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        bit[i] = s[n - 1 - i] - '0';
    }
    return bit.to_ulong();
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cout.tie(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int num = convtoint(s);
        cout << maxno(n, k, num) << "\n";
    }
    return 0;
}