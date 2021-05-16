#include <iostream>

using namespace std;

extern "C" void pcpp(int a)
{
    cout << "\nC++ Function : " << a;
}
