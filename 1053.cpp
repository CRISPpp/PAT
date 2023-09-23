#include <bits/stdc++.h>
using namespace std;
const int N = 128;
vector<int> edges[N];

int weight[N];
int n, m, s;

vector<int> path;
vector<vector<int>> ret;

void dfs(int curId, int curVal)
{
    curVal += weight[curId];

    if (curVal >= s)
    {
        if (curVal == s && edges[curId].size() == 0)
        {
            ret.emplace_back(path);
        }
        return;
    }

    for (int nxt : edges[curId])
    {
        path.emplace_back(weight[nxt]);
        dfs(nxt, curVal);
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    for (int i = 0; i < m; i++)
    {
        int id;
        int k;
        int chi;
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &chi);
            edges[id].emplace_back(chi);
        }
        sort(edges[id].begin(), edges[id].end(), [&](int id1, int id2)
             { return weight[id1] > weight[id2]; });
    }
    path.emplace_back(weight[0]);
    dfs(0, 0);

    sort(ret.begin(), ret.end(), [&](vector<int> a, vector<int> b)
         {
        int idx = 0;
        while (idx < a.size() && idx < b.size() && a[idx] == b[idx]) idx ++;
        int aa = (idx == a.size() ? 0 : a[idx]);
        int bb = (idx == b.size() ? 0 : b[idx]);
        return aa > bb; });

    for (auto &p : ret)
    {
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i];
            if (i == p.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}