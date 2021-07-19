#include <iostream>

using namespace std;

extern "C" void printint(int a)
{
    cout << "Number is : " << a << flush;
}