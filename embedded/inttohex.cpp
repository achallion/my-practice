#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int i;
    while (cin >> i)
    {
        cout << dec << i << " = " << hex << "0x" << i << " = " << bitset<8 * sizeof(int)>(i) << "\n";
    }
}