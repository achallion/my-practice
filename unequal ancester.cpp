#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void enter(vector<int> &bt, TreeNode *A, int i, unordered_set<int> &s)
{
    // base
    if (A == NULL)
        return;

    // rec
    int arrsize = 1 << (int)(log2(i) + 2);
    if (arrsize > bt.size())
        bt.resize(arrsize);

    bt[0]++;
    bt[i] = A->val;
    s.insert(i);
    enter(bt, A->left, i << 1, s);
    enter(bt, A->right, (i << 1) + 1, s);
}

int solve(TreeNode *A, int B)
{
    vector<int> bt;
    unordered_set<int> s;
    bt.push_back(0);
    enter(bt, A, 1, s);
    if (s.size() != bt[0])
        return -1;

    int count = 0;
    for (int i : s)
    {
        int pari = i >> B;
        if (pari >= 1 && bt[pari] != bt[i])
            count++;
    }
    return count;
}

