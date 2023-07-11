#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 1e4 + 10;
int tarTime[N];
int costTime[N];
int startTime[N];
int window[N];

struct cmp
{
    bool operator()(int a, int b)
    {
        return startTime[a] > startTime[b];
    }
};

int main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    memset(window, 0, sizeof(window));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string tmptime;
        int cost;
        cin >> tmptime >> cost;
        costTime[i] = cost * 60;
        int tmpS = 0;
        tmpS += stoi(tmptime.substr(6, 2));
        tmpS += stoi(tmptime.substr(3, 2)) * 60;
        tmpS += stoi(tmptime.substr(0, 2)) * 60 * 60;

        startTime[i] = tmpS;
    }

    priority_queue<int, vector<int>, cmp> q;
    long long ret = 0;

    for (int i = 0; i < n; i++)
        q.push(i);
    int curTime = 8 * 60 * 60;
    int cnt = 0;
    while (q.size() > 0)
    {
        int nxtwindow = -1;
        for (int i = 0; i < k; i++)
        {
            if (window[i] <= curTime)
            {
                nxtwindow = i;
                break;
            }
        }
        if (nxtwindow != -1 && startTime[q.top()] <= curTime)
        {
            int curCus = q.top();
            q.pop();
            if (startTime[curCus] > 17 * 60 * 60)
                continue;
            cnt++;
            tarTime[curCus] = curTime + costTime[curCus];
            ret += (curTime - startTime[curCus]);
            window[nxtwindow] = tarTime[curCus];
        }
        else
        {

            curTime++;
        }
    }
    cout << fixed << setprecision(1) << (double)ret / 60 / cnt << endl;
}