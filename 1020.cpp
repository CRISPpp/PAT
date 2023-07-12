#include <bits/stdc++.h>
using namespace std;

const int N = 64;

int post[N];
int inOrder[N];

int n;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int a)
    {
        val = a;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *getTree(int postL, int postR, int inL, int inR)
{
    if (postL > postR)
        return nullptr;
    TreeNode *ret = new TreeNode(post[postR]);
    int idx = inL;
    while (inOrder[idx] != post[postR])
    {
        idx++;
    }
    int lLen = idx - inL;
    ret->left = getTree(postL, postL + lLen - 1, inL, idx - 1);

    int rLen = inR - idx;
    ret->right = getTree(postL + lLen, postR - 1, idx + 1, inR);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        post[i] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        inOrder[i] = tmp;
    }

    TreeNode *ret = getTree(0, n - 1, 0, n - 1);

    queue<TreeNode *> q;
    q.push(ret);
    while (q.size() > 0)
    {
        auto it = q.front();
        q.pop();
        if (it->left != nullptr)
            q.push(it->left);
        if (it->right != nullptr)
            q.push(it->right);
        cout << it->val;
        if (q.size() == 0)
            cout << endl;
        else
            cout << " ";
    }
}