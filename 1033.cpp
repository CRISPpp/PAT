#include <bits/stdc++.h>
using namespace std;

const int N = 512;
double cMax, d, dAvg;
int n;

vector<pair<double, double>> cs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> cMax >> d >> dAvg >> n;
    for (int i = 0; i < n; i++)
    {
        pair<double, double> tmp;
        cin >> tmp.first >> tmp.second;
        cs.emplace_back(tmp);
    }
    pair<double, double> ttmp = {0.0, d};
    cs.emplace_back(ttmp);

    sort(cs.begin(), cs.end(), [&](pair<double, double> a, pair<double, double> b)
         { return a.second < b.second; });

    if (cs[0].second != 0)
    {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    vector<int> dTmp;
    double ret = 0.0;
    double maxDis = cMax * dAvg;
    double cur = 0;
    double curC = 0;
    int idx = 0;
    while (cur < d)
    {
        int nxt = idx;
        if (cur + maxDis < cs[idx + 1].second)
        {
            cout << "The maximum travel distance = " << fixed << setprecision(2) << cur + maxDis << endl;
            return 0;
        }
        int minNxt = -1;
        for (int i = idx + 1; i < cs.size(); i++)
        {
            if (cs[i].second > cur + maxDis)
            {
                break;
            }
            if (cs[i].first < cs[nxt].first || (abs(cs[i].first - cs[nxt].first) < 1e-6))
            {
                nxt = i;
                break;
            }
            if (minNxt == -1 || cs[minNxt].first > cs[i].first)
            {
                minNxt = i;
            }
        }

        if (nxt == idx)
        {
            dTmp.emplace_back(nxt);
            ret += (maxDis - curC) / dAvg * cs[idx].first;
            curC = maxDis - (cs[minNxt].second - cs[idx].second);
            idx = minNxt;
            cur = cs[idx].second;
        }
        else
        {
            int needDis = cs[nxt].second - cur;
            if (curC >= needDis)
            {
                curC -= needDis;
            }
            else
            {
                ret += (needDis - curC) / dAvg * cs[idx].first;
                curC = 0;
            }
            idx = nxt;
            cur = cs[idx].second;
        }
    }
    if (curC > 0)
        ret -= (curC / dAvg * cs[dTmp.back()].first);

    if (abs(cur - d) < 1e-6)
    {
        cout << fixed << setprecision(2) << ret << endl;
    }
    else
    {
        cout << "The maximum travel distance = " << fixed << setprecision(2) << cur << endl;
    }
}