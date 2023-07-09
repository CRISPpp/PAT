#include <bits/stdc++.h>
using namespace std;

int n, m;

bool edge[100][100];

int d[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    if (m == 0)
    {
        cout << n << endl;
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int f, k;
        cin >> f >> k;
        for (int j = 0; j < k; j++)
        {
            int nxt;
            cin >> nxt;
            d[nxt]++;
            edge[f][nxt] = true;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }

    while (q.size() > 0)
    {
        int ret = 0;
        int s = q.size();
        while (s > 0)
        {
            auto it = q.front();
            q.pop();
            bool find = false;
            for (int i = 1; i <= n; i++)
            {
                if (edge[it][i])
                {
                    find = true;
                    q.push(i);
                }
            }
            if (!find)
            {
                ret++;
            }

            s--;
        }
        cout << ret;
        if (q.size() == 0)
            cout << endl;
        else
            cout << " ";
    }
}