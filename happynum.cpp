#include <iostream>

using namespace std;

int sqr(int n)
{
    return n * n;
}

int sd(int num)
{
    int s = 0;
    while (num > 0)
    {
        s += sqr(num % 10);
        num /= 10;
    }
    return s;
}

int main()
{
    int num;
    cin >> num;
    int s = sd(num);
    int f = sd(sd(num));
    while (s != f)
    {
        cout << s << " " << f << "\n";
        s = sd(s);
        f = sd(sd(f));
    }
    cout << s << " " << f << "\n";

    if (s == 1)
        cout << "happy num";
}