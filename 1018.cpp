// 三个点过不了，不知道哪的细节错了艹
#include <bits/stdc++.h>
using namespace std;

const int N = 512;

int n, cmax, tar, m;

int c[N];
int edge[N][N];
int dist[N];

void dijkstra()
{
    memset(dist, -1, sizeof(dist));
    bool vis[n + 1] = {false};
    dist[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int curIdx = -1;
        for (int j = 0; j <= n; j++)
        {
            if (!vis[j] && dist[j] != -1 && (curIdx == -1 || dist[j] < dist[curIdx]))
            {
                curIdx = j;
            }
        }
        vis[curIdx] = true;
        for (int j = 0; j <= n; j++)
        {
            if (edge[curIdx][j] != -1 && (dist[j] == -1 || dist[j] > dist[curIdx] + edge[curIdx][j]))
            {
                dist[j] = dist[curIdx] + edge[curIdx][j];
            }
        }
    }
}

int take = -1, takeBack = -1;
vector<int> ret;

void dfs(int curDis, int curIdx, int needToTake, int haveNow, unordered_map<int, bool> &vis, vector<int> &tmp)
{
    if (curDis > dist[tar])
    {
        return;
    }
    if (curDis == dist[tar] && curIdx == tar)
    {
        if (take == -1 || take > needToTake)
        {
            ret = tmp;
            take = needToTake;
            takeBack = haveNow;
        }
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if (edge[curIdx][j] != -1 && !vis[j])
        {
            tmp.emplace_back(j);
            vis[j] = true;
            int ttt = cmax / 2;
            if (c[j] >= ttt)
            {
                dfs(curDis + edge[curIdx][j], j, needToTake, haveNow + (c[j] - ttt), vis, tmp);
            }
            else
            {
                int need = ttt - c[j];
                if (need <= haveNow)
                {
                    dfs(curDis + edge[curIdx][j], j, needToTake, haveNow - need, vis, tmp);
                }
                else
                {
                    dfs(curDis + edge[curIdx][j], j, needToTake - haveNow + need, 0, vis, tmp);
                }
            }
            vis[j] = false;
            tmp.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(edge, -1, sizeof(edge));

    cin >> cmax >> n >> tar >> m;

    for (int i = 1; i <= n; i++)
    {
        int tmpC;
        cin >> tmpC;
        c[i] = tmpC;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
    }
    dijkstra();
    vector<int> tmp;
    tmp.emplace_back(0);
    unordered_map<int, bool> mp;
    mp[0] = true;
    dfs(0, 0, 0, 0, mp, tmp);
    cout << take << " ";

    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i];
        if (i == ret.size() - 1)
            cout << " ";
        else
            cout << "->";
    }
    cout << takeBack << endl;
}