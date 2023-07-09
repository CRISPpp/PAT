#include <bits/stdc++.h>
using namespace std;

int n, m, c1, c2;
int edge[505][505];
int dis[505];
int team[505];
bool vis[505];
int cnt = 0;
int maxNum = 0;

void dijkstra()
{
    dis[c1] = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] != -1 && (cur == -1 || dis[j] < dis[cur]))
                cur = j;
        }
        vis[cur] = true;
        for (int j = 0; j < n; j++)
        {
            if (edge[cur][j] != -1 && (dis[j] == -1 || dis[j] > dis[cur] + edge[cur][j]))
            {
                dis[j] = dis[cur] + edge[cur][j];
            }
        }
    }
}

map<vector<int>, bool> mp;

void dfs(int cur, int curNum, int cost, int cc, int lst)
{
    if (mp[{cur, curNum, cost, cc}])
        return;
    mp[{cur, curNum, cost, cc}] = true;
    if (cc > n || cost > dis[c2])
        return;
    curNum += team[cur];
    if (cur == c2 && cost == dis[c2])
    {
        maxNum = max(maxNum, curNum);
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != lst && edge[cur][i] != -1)
        {
            dfs(i, curNum, cost + edge[cur][i], cc + 1, cur);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(edge, -1, sizeof(edge));
    memset(dis, -1, sizeof(dis));
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
        cin >> team[i];

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
    }

    dijkstra();
    for (int i = 0; i < n; i++)
        vis[i] = false;
    dfs(c1, 0, 0, 0, -1);
    cout << cnt << " " << maxNum << endl;
    return 0;
}