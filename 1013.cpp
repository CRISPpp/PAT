#include <bits/stdc++.h>
using namespace std;
int p[1050];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(p, -1, sizeof(p));
    int n, m, k;
    map<int, vector<int>> mp;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].emplace_back(b);
        mp[b].emplace_back(a);
    }

    for (int i = 0; i < k; i++)
    {
        int tar;
        cin >> tar;

        for (int j = 1; j <= n; j++)
            p[j] = j;

        for (int j = 1; j <= n; j++)
        {
            if (j == tar)
                continue;
            for (int &edge : mp[j])
            {
                if (edge == tar)
                    continue;
                p[find(j)] = find(edge);
            }
        }
        set<int> setTmp;
        for (int j = 1; j <= n; j++)
        {
            if (j != tar)
                setTmp.insert(p[find(j)]);
        }
        cout << setTmp.size() - 1 << endl;
    }
}