#ifndef HELPER_CPP
#define HELPER_CPP

#include <bits/stdc++.h>

using namespace std;

namespace NAM
{
    string createstr(char a, int count)
    {
        string temp(count, a);
        return temp;
    }

    string createstr(string a, int count)
    {
        string temp;
        for (int i = 0; i < count; i++)
            temp = temp + a;
        return temp;
    }

}; // namespace NAM

#endif