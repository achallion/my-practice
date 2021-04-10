// f(x) = f(x-1)^2 + 10x + 9 f(x - 1) + 2
// f(0) = 1

#include <iostream>

using namespace std;

#define ll long long

ll recf(ll x)
{
    // base
    if (x == 0)
    {
        return 1 + 10 + 9 + 2;
    }

    // rec

    ll fx_1 = recf(x - 1);
    ll ans = fx_1 * fx_1 + 10 * x + 9 * fx_1 + 2;
    return ans;
}

ll dyp(ll x)
{
    ll dp[11];
    dp[0] = 1 + 10 + 9 + 2;

    for (int i = 1; i <= 10; i++)
        dp[i] = (dp[i - 1] * dp[i - 1]) + 10 * i + 9 * dp[i - 1] + 2;

    return dp[10];
}

ll mul(ll x)
{

}

int main()
{
    long long x = 10;
    cout << recf(x) << "\n"
         << dyp(x) << "\n"
         << mul(x);
    return 0;
}