#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double n1[1001];
    double n2[1001];
    memset(n1, 0.0, sizeof(n1));
    memset(n2, 0.0, sizeof(n2));
    int k1, k2;

    cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        int a;
        double b;
        cin >> a >> b;
        n1[a] += b;
    }

    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        int a;
        double b;
        cin >> a >> b;
        n2[a] += b;
    }

    int k3 = 0;
    double n3[1001];
    memset(n3, 0.0, sizeof(n3));
    for (int i = 1000; i >= 0; i--)
    {
        if (abs(n1[i] + n2[i]) >= 1e-6)
        {
            n3[i] = n1[i] + n2[i];
            k3++;
        }
    }

    if (k3 == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << k3 << " ";
    int cnt = 0;
    for (int i = 1000; i >= 0; i--)
    {
        if (abs(n3[i]) >= 1e-6)
        {
            cnt++;
            cout << i << " " << fixed << setprecision(1) << n3[i];
            if (cnt != k3)
                cout << " ";
            else
                cout << endl;
        }
    }
}