// 把树想象成链，随机选一个点递归到最深的必定是最深的结果，再从最深的结果遍历一遍得到所有的最深节点
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n;
vector<int> edge[N];
int finalLen1[N];
int finalLen2[N];
set<int> ret;
int maxLen1 = 0;
int maxLen2 = 0;
int p[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void dfs(bool isOne, int idx, int deep)
{
    if (isOne)
    {
        finalLen1[idx] = deep;
        maxLen1 = max(maxLen1, deep);
    }
    else
    {
        finalLen2[idx] = deep;
        maxLen2 = max(maxLen2, deep);
    }
    for (int i : edge[idx])
    {
        if (isOne)
        {
            if (finalLen1[i] == -1)
            {
                dfs(isOne, i, deep + 1);
            }
        }
        else
        {
            if (finalLen2[i] == -1)
            {
                dfs(isOne, i, deep + 1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        finalLen1[i] = -1;
        finalLen2[i] = -1;
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
        p[find(a)] = find(b);
    }

    set<int> tmpSet;
    for (int i = 1; i <= n; i++)
        tmpSet.insert(find(i));
    if (tmpSet.size() > 1)
    {
        cout << "Error: " << to_string(tmpSet.size()) << " components" << endl;
        return 0;
    }
    dfs(true, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (finalLen1[i] == maxLen1)
        {
            ret.insert(i);
        }
    }
    dfs(false, *(ret.begin()), 0);
    for (int i = 1; i <= n; i++)
    {
        if (finalLen2[i] == maxLen2)
        {
            ret.insert(i);
        }
    }
    for (auto it = ret.begin(); it != ret.end(); it++)
    {
        cout << *it << endl;
    }
}