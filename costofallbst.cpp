#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define mod 1000000007

int solve(int A)
{
    vector<int> arr(A);
    for (int i = 1; i <= A; i++)
        arr[i - 1] = i;

    long long sum = 0;
    do
    {
        for (int i = 1; i < arr.size(); i++)
            sum = (sum + (arr[i] < arr[0] ? arr[i] : 0) % mod) % mod;
    } while (next_permutation(arr.begin(), arr.end()));
    return sum;
}

int solveop1(int A)
{
    vector<int> arr(A);
    for (int i = 1; i <= A; i++)
        arr[i - 1] = i;

    long long sum = 0;
    do
    {
        int num = arr[0];
        long long add = ((1LL * num * (num + 1 + 0LL)) >> 1) - num;
        sum = (sum + add % mod) % mod;
    } while (next_permutation(arr.begin(), arr.end()));
    return sum;
}

int solveop2(int A)
{
    long long sum = 0;
    long long fact = 1;

    for(int i = 1;i<= A;i++)
    {
        long long sumtilli = 1LL * i * (0LL + i + 1);
        sumtilli >>= 1;
        int toadd = (sumtilli - i )%mod;
        sum = (sum + toadd) % mod;
        
        if(i < A)
            fact = (fact * i) % mod;
        
    }
    
    sum = (sum * fact) % mod;
    return sum;
}

int main()
{
    int i;
    cin >> i;
   /* cout << solve(i) << flush;
    cout << "\n"
         << solveop1(i) << flush;*/
    cout << "\n"
         << solveop2(i);
    return 0;
}