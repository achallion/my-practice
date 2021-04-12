#include <iostream>

using namespace std;

void rec(string s, string ans = "", int tot = 3)
{
    // base
    if (!tot)
    {
        cout << ans << "\n";
        return;
    }

    // rec
    ans.push_back(' ');
    for (int i = 0; i < s.size(); i++)
    {
        *prev(ans.end()) = s[i];
        rec(s.substr(i + 1, s.size() - 1), ans, tot - 1);
    }
}

int main()
{
    string s = "abcd";
    rec(s);
    return 0;
}