#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> mp[3000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        string name;
        cin >> name;
        int c;
        cin >> c;
        while (c--)
        {
            int idx;
            cin >> idx;
            mp[idx].emplace_back(name);
        }
    }

    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", i, mp[i].size());
        sort(mp[i].begin(), mp[i].end());
        for (auto it = mp[i].begin(); it != mp[i].end(); it++)
        {
            printf("%s\n", (*it).c_str());
        }
    }
}