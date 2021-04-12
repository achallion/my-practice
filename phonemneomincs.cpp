#include <iostream>
#include <string>
#include <vector>

using namespace std;

string num[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
int n = 10;

void rec(string n, string str[], int ls, int len, int i = 0)
{
    // base
    if (i == len)
    {
        for (int j = 0; j < ls; j++)
        {
            cout << str[j] << "\n";
        }
        return;
    }

    // rec
    int dig = n[i] - '0';
    string alphas = num[dig];
    string ans[ls * alphas.size()];
    for (int i = 0; i < ls; i++)
    {
        for (int j = 0; j < alphas.size(); j++)
        {
            ans[i * alphas.size() + j] = str[i];
            ans[i * alphas.size() + j].push_back(alphas[j]);
        }
    }

    rec(n, ans, ls * alphas.size(), len, i + 1);
}

void dyp(string num)
{
    vector<string> ans;
    ans.push_back("");

    for (int i = 0; i < num.size(); i++)
    {
        vector<string> temp(ans);
        ans.clear();
        string alpha = ::num[num[i] - '0'];
        for (int j = 0; j < alpha.size(); j++)
        {
            for (string str : temp)
            {
                str.push_back(alpha[j]);
                ans.push_back(str);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    string strarr[1];
    //rec("234", strarr, 1, 3);
    dyp("234");
    return 0;
}