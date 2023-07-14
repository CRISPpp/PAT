#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int d[N];
int preSm[N];
int n;
int m;
typedef pair<int, int> PII;
vector<PII> ret;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        d[i] = tmp;
        preSm[i] = preSm[i - 1] + tmp;
    }

    int minGap = -1;

    for (int i = 0; i <= n; i++)
    {
        int tar = preSm[i] + m;
        int idx = (lower_bound(preSm + 1, preSm + n, tar) - preSm);
        int gap = preSm[idx] - preSm[i] - m;
        if (gap < 0)
            break;
        if (minGap == -1 || gap <= minGap)
        {
            if (minGap == -1 || gap < minGap)
            {
                minGap = gap;
                ret.clear();
            }
            PII tmp = {i + 1, idx};
            ret.emplace_back(tmp);
        }
    }
    for (PII i : ret)
    {
        cout << i.first << "-" << i.second << endl;
    }
}