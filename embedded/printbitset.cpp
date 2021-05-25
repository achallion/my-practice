#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    constexpr int maxi = 8;
    bitset<maxi> a;
    while (cin >> a)
    {
        cout << a << "\n";
        for (int i = 7; i >= 0; i--)
            cout << a[i];

        cout << "\n";
    }
    return 0;
}