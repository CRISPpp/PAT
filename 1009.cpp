#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double ret[3000];
    double final[3000];
    memset(ret, 0.0, sizeof(ret));
    int k;
    cin >> k;
    int maxp;
    for (int i = 0; i < k; i++)
    {
        int a;
        double b;
        cin >> a >> b;
        ret[a] = b;
        if (i == 0)
        {
            maxp = a;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        double b;
        cin >> a >> b;
        for (int j = 0; j <= maxp; j++)
        {
            if (abs(ret[j]) > 1e-6)
            {
                final[j + a] += ret[j] * b;
            }
        }
    }

    int cnt = 0;
    for (int i = 2500; i >= 0; i--)
    {
        if (abs(final[i]) > 1e-6)
            cnt++;
    }
    if (cnt == 0)
    {
        cout << cnt << endl;
        return 0;
    }
    cout << cnt << " ";
    int tmp = 0;
    for (int i = 2500; i >= 0; i--)
    {
        if (abs(final[i]) > 1e-6)
        {
            tmp++;
            cout << fixed << setprecision(1) << i << " " << final[i];
            if (tmp == cnt)
                cout << endl;
            else
                cout << " ";
        }
    }
}