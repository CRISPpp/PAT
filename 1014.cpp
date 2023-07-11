#include <bits/stdc++.h>
using namespace std;

int n, m, k, q;

queue<int> customer[32];
int costTime[2048];
int tarTime[2048];
int qTime[32];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(tarTime, -1, sizeof(tarTime));
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++)
    {
        int a;
        cin >> a;
        costTime[i] = a;
    }

    int curTime = 60 * 8;
    int cnt = 0;
    while (cnt < k)
    {
        // 检查到没到时间
        for (int i = 0; i < n; i++)
        {
            while (customer[i].size() > 0 && tarTime[customer[i].front()] <= curTime)
            {
                cnt++;
                qTime[i] -= costTime[customer[i].front()];
                customer[i].pop();
            }
        }
        while (true)
        {
            int nxt = -1;
            for (int i = 1; i <= k; i++)
            {
                if (tarTime[i] == -1)
                {
                    nxt = i;
                    break;
                }
            }
            int tarQ = -1;
            int curSize = 0;
            for (int i = 0; i < n; i++)
            {
                if (customer[i].size() < m && (tarQ == -1 || customer[i].size() < curSize))
                {
                    curSize = customer[i].size();
                    tarQ = i;
                }
            }

            if (nxt != -1 && tarQ != -1)
            {
                tarTime[nxt] = curTime + costTime[nxt] + qTime[tarQ];
                qTime[tarQ] += costTime[nxt];
                customer[tarQ].push(nxt);
            }
            else
            {
                break;
            }
        }

        curTime++;
    }

    for (int i = 0; i < q; i++)
    {
        int tar;
        cin >> tar;
        if (tarTime[tar] - costTime[tar] >= 17 * 60)
        {
            cout << "Sorry" << endl;
            continue;
        }

        int min = tarTime[tar] / 60;
        int sec = tarTime[tar] % 60;
        string ret;
        if (min < 10)
            ret += "0";
        ret += to_string(min);
        ret += ":";
        if (sec < 10)
            ret += "0";
        ret += to_string(sec);
        cout << ret << endl;
    }
}