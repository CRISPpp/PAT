#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mm;
    cin >> n >> mm;

    int c[3000];
    int m[3000];
    int e[3000];
    int a[3000];
    int crank[3000];
    int mrank[3000];
    int erank[3000];
    int arank[3000];

    unordered_map<string, int> mp;
    unordered_map<int, int> ccnt;
    unordered_map<int, int> mcnt;
    unordered_map<int, int> ecnt;
    unordered_map<int, int> acnt;

    for (int i = 0; i < n; i++)
    {
        string id;
        int cc, mm, ee, aa;
        cin >> id >> cc >> mm >> ee;
        mp[id] = i;
        c[i] = cc;
        m[i] = mm;
        e[i] = ee;
        a[i] = (cc + mm + ee);
        ccnt[c[i]]++;
        mcnt[m[i]]++;
        ecnt[e[i]]++;
        acnt[a[i]]++;
    }

    int ccopy[3000];
    int mcopy[3000];
    int ecopy[3000];
    int acopy[3000];
    int cs = 0, ms = 0, es = 0, as = 0;
    for (auto &a : ccnt)
    {
        ccopy[cs++] = a.first;
    }
    for (auto &a : mcnt)
    {
        mcopy[ms++] = a.first;
    }
    for (auto &a : ecnt)
    {
        ecopy[es++] = a.first;
    }

    for (auto &a : acnt)
    {
        acopy[as++] = a.first;
    }

    sort(ccopy, ccopy + cs);
    sort(mcopy, mcopy + ms);
    sort(ecopy, ecopy + es);
    sort(acopy, acopy + as);
    // 0,1,2,3,4
    for (int i = 0; i < n; i++)
    {
        int idx = (lower_bound(ccopy, ccopy + cs, c[i]) - ccopy);
        crank[i] = (cs - (lower_bound(ccopy, ccopy + cs, c[i]) - ccopy));
        for (int j = idx + 1; j < cs; j++)
        {
            if (ccnt[ccopy[j]] > 1)
            {
                crank[i] += ccnt[ccopy[j]] - 1;
            }
        }
        idx = (lower_bound(mcopy, mcopy + ms, m[i]) - mcopy);
        mrank[i] = (ms - (lower_bound(mcopy, mcopy + ms, m[i]) - mcopy));
        for (int j = idx + 1; j < ms; j++)
        {
            if (mcnt[mcopy[j]] > 1)
            {
                mrank[i] += mcnt[mcopy[j]] - 1;
            }
        }
        idx = (lower_bound(ecopy, ecopy + es, e[i]) - ecopy);
        erank[i] = (es - (lower_bound(ecopy, ecopy + es, e[i]) - ecopy));
        for (int j = idx + 1; j < es; j++)
        {
            if (ecnt[ecopy[j]] > 1)
            {
                erank[i] += ecnt[ecopy[j]] - 1;
            }
        }
        idx = (lower_bound(acopy, acopy + as, a[i]) - acopy);
        arank[i] = (as - (lower_bound(acopy, acopy + as, a[i]) - acopy));
        for (int j = idx + 1; j < as; j++)
        {
            if (acnt[acopy[j]] > 1)
            {
                arank[i] += acnt[acopy[j]] - 1;
            }
        }
    }

    for (int i = 0; i < mm; i++)
    {
        string tarId;
        cin >> tarId;
        if (mp.count(tarId) == 0)
        {
            cout << "N/A" << endl;
            continue;
        }
        int idx = mp[tarId];
        int maxRank = arank[idx];
        char mark = 'A';
        if (maxRank > crank[idx])
        {
            maxRank = crank[idx];
            mark = 'C';
        }
        if (maxRank > mrank[idx])
        {
            maxRank = mrank[idx];
            mark = 'M';
        }
        if (maxRank > erank[idx])
        {
            maxRank = erank[idx];
            mark = 'E';
        }
        cout << maxRank << " " << mark << endl;
    }
}