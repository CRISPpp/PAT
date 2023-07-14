#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int pre[N];

int lst = -1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            cin >> lst;
        }
        else
        {
            cin >> pre[i + 1];
            pre[i + 1] += pre[i];
        }
    }

    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            a ^= b;
            b = a ^ b;
            a = b ^ a;
        }

        int ret1 = pre[b] - pre[a];
        int ret2 = pre[n] - pre[b];
        ret2 += lst;
        ret2 += pre[a] - pre[1];
        cout << min(ret1, ret2) << endl;
    }
}