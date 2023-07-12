// 傻逼大模拟艹
#include <bits/stdc++.h>
using namespace std;
const int K = 128;
const int N = 10000 + 10;
int n, k, m;
class Cus
{
public:
    int idx;
    int arriveTime;
    int p;
    int tarTime;
    int serveTime;
    bool isVip;
    Cus(int a, int pp, int t, bool i, int idx, int serve)
    {
        arriveTime = a;
        p = pp;
        tarTime = t;
        isVip = i;
        this->idx = idx;
        serveTime = serve;
    }
};

struct cmp
{
    bool operator()(Cus a, Cus b)
    {
        return a.arriveTime > b.arriveTime;
    }
};

int q[K];

vector<int> vipTableIdx;

int cntTable[K];
bool vis[N];

priority_queue<Cus, vector<Cus>, cmp> curQ;
priority_queue<Cus, vector<Cus>, cmp> vipQ;
vector<Cus> ret;

string tFormat(int time)
{
    int hour = 0, minn = 0, sec = 0;
    hour = time / (3600);
    time %= 3600;
    minn = time / 60;
    time %= 60;
    sec = time;
    string rret = "";
    if (hour < 10)
        rret += '0';
    rret += to_string(hour);
    rret += ":";
    if (minn < 10)
        rret += '0';
    rret += to_string(minn);
    rret += ":";
    if (sec < 10)
        rret += '0';
    rret += to_string(sec);
    return rret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(q, 0, sizeof(q));
    memset(cntTable, 0, sizeof(cntTable));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        int a = 0;
        a += stoi(t.substr(6, 2));
        a += stoi(t.substr(3, 2)) * 60;
        a += stoi(t.substr(0, 2)) * 60 * 60;
        int p;
        cin >> p;
        p *= 60;
        bool isVip;
        cin >> isVip;
        Cus cus(a, p, -1, isVip, i, -1);
        curQ.push(cus);
        if (isVip)
        {
            vipQ.push(cus);
        }
    }

    cin >> k >> m;
    for (int i = 0; i < m; i++)
    {
        int tmpVipIdx;
        cin >> tmpVipIdx;
        vipTableIdx.emplace_back(tmpVipIdx);
    }

    int curTime = 8 * 3600;
    while (curQ.size() > 0)
    {
        if (curTime > 21 * 3600)
            break;
        int nxtVipTable = -1;
        for (int i = 0; i < m; i++)
        {
            if (q[vipTableIdx[i]] <= curTime && (nxtVipTable == -1))
            {
                nxtVipTable = vipTableIdx[i];
                break;
            }
        }
        if (nxtVipTable != -1 && vipQ.size() > 0 && vipQ.top().arriveTime <= curTime)
        {
            auto it = vipQ.top();
            vipQ.pop();
            if (vis[it.idx])
                continue;
            cntTable[nxtVipTable]++;
            vis[it.idx] = true;
            it.serveTime = curTime;
            it.tarTime = curTime + it.p;
            q[nxtVipTable] = it.tarTime;
            ret.emplace_back(it);
        }
        else
        {
            int nxtTable = -1;
            for (int i = 1; i <= k; i++)
            {
                if (q[i] <= curTime)
                {
                    nxtTable = i;
                    break;
                }
            }
            if (nxtTable != -1 && curQ.size() > 0 && curQ.top().arriveTime <= curTime)
            {
                auto it = curQ.top();
                curQ.pop();
                if (vis[it.idx])
                    continue;
                vis[it.idx] = true;
                cntTable[nxtTable]++;
                it.serveTime = curTime;
                it.tarTime = curTime + it.p;
                q[nxtTable] = it.tarTime;
                ret.emplace_back(it);
            }
            else
            {
                curTime++;
            }
        }
    }
    for (int i = 0; i < ret.size(); i++)
    {
        auto it = ret[i];
        int wait = it.serveTime - it.arriveTime;
        int tmpWait = wait / 60;
        if (wait % 60 != 0)
            tmpWait++;
        cout << tFormat(it.arriveTime) << " " << tFormat(it.serveTime) << " " << tmpWait << endl;
    }
    for (int i = 1; i <= k; i++)
    {
        cout << cntTable[i];
        if (i == k)
            cout << endl;
        else
            cout << " ";
    }
}
