#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

int n;
vector<int> pre;
vector<int> inorder;
bool f = true;

Node *getTree(int preL, int preRight, int inL, int inR, bool reverse)
{
    if (f == false)
        return nullptr;
    if (preL > preRight)
        return nullptr;
    int root = pre[preL];
    int idx = inL;
    while (idx <= inR && inorder[idx] != root)
        idx++;
    if (reverse)
    {
        while (idx + 1 <= inR && inorder[idx + 1] == root)
            idx++;
    }
    if (idx > inR)
    {
        f = false;
        return nullptr;
    }
    Node *ret = new Node(root);
    int lLen = (idx - inL);
    int rLen = (inR - idx);
    ret->left = getTree(preL + 1, preL + 1 + lLen - 1, inL, idx - 1, reverse);
    ret->right = getTree(preL + 1 + lLen, preL + 1 + lLen + rLen - 1, idx + 1, inR, reverse);
    return ret;
}

vector<int> postRet;

void post(Node *root)
{
    if (root == nullptr)
        return;
    post(root->left);
    post(root->right);
    postRet.emplace_back(root->val);
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
        pre.emplace_back(tmp);
        inorder.emplace_back(tmp);
    }

    sort(inorder.begin(), inorder.end());
    Node *ret = getTree(0, n - 1, 0, n - 1, false);
    if (!f)
    {
        f = true;
        sort(inorder.begin(), inorder.end(), [&](int a, int b)
             { return a > b; });
        ret = getTree(0, n - 1, 0, n - 1, true);
    }
    if (f)
    {
        post(ret);
        cout << "YES" << endl;
        for (int i = 0; i < postRet.size(); i++)
        {
            cout << postRet[i];
            if (i == postRet.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}