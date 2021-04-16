#include <iostream>
#include <vector>

using namespace std;

void flipandinvert(vector<vector<int>> &v)
{
    int l = v.size();
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < (l >> 1); j++)
        {
            bool temp = v[i][j];
            v[i][j] = v[i][l - 1 - j];
            v[i][l - 1 - j] = temp;
        }
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            v[i][j] ^= 1;
        }
    }
}

int main()
{
    int arr2[4][4] = {{1, 1, 0, 0},
                      {1, 0, 0, 1},
                      {0, 1, 1, 1},
                      {1, 0, 1, 0}};

    int arr1[3][3] = {{1, 0, 1},
                      {1, 1, 1},
                      {0, 1, 1}};

    vector<vector<int>> v1 = vector<vector<int>>(3, vector<int>(3, 0));
    vector<vector<int>> v2(4, vector<int>(4, 0));

    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            v1[i][j] = arr1[i][j];
        }
    }

    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
        {
            v2[i][j] = arr2[i][j];
        }
    }

    flipandinvert(v1);
    flipandinvert(v2);

    // print
    cout << "\n\n";
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
        {
            cout << v2[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}