#include <bits/stdc++.h>
using namespace std;

const int N = 512;
int n, m;
class Edge
{
public:
    int f;
    int t;
    int length;
    int cost;
    Edge(int f, int t, int length, int cost)
    {
        this->f = f;
        this->t = t;
        this->length = length;
        this->cost = cost;
    }
};

vector<Edge> es[N];
bool vis[N];
int start, ed;
int dis[N];

void dijkstra()
{
    dis[start] = 0;
    int cnt = 0;
    while (cnt < n)
    {
        int nxt = -1;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && (dis[i] != -1) && (nxt == -1 || dis[i] < dis[nxt]))
            {
                nxt = i;
                break;
            }
        }
        vis[nxt] = true;
        for (Edge e : es[nxt])
        {
            if (dis[e.t] == -1 || dis[e.t] > dis[e.f] + e.length)
            {
                dis[e.t] = dis[e.f] + e.length;
            }
        }
        cnt++;
    }
}

vector<int> retPath;
int minCost = -1;

void dfs(unordered_map<int, bool> &visMp, vector<int> &rt, int idx, int l, int c)
{
    if (l > dis[ed])
        return;
    if (l == dis[ed])
    {
        if (idx == ed && (minCost == -1 || minCost > c))
        {
            minCost = c;
            retPath = rt;
        }
        return;
    }

    for (Edge e : es[idx])
    {
        if (!visMp[e.t])
        {
            visMp[e.t] = true;
            rt.emplace_back(e.t);
            dfs(visMp, rt, e.t, l + e.length, c + e.cost);
            rt.pop_back();
            visMp[e.t] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis, -1, sizeof(dis));
    cin >> n >> m >> start >> ed;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Edge edge(a, b, c, d);
        Edge edge2(b, a, c, d);
        es[b].emplace_back(edge2);
        es[a].emplace_back(edge);
    }
    dijkstra();
    unordered_map<int, bool> visMp;
    visMp[start] = true;
    vector<int> tmpRet;
    tmpRet.emplace_back(start);
    dfs(visMp, tmpRet, start, 0, 0);
    for (int i = 0; i < retPath.size(); i++)
    {
        cout << retPath[i] << " ";
    }
    cout << dis[ed] << " " << minCost << endl;
}