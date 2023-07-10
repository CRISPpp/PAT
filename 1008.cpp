#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int cur = 0;
    int ret = 0;
    while (n > 0)
    {
        int tar;
        cin >> tar;
        if (tar >= cur)
        {
            ret += (tar - cur) * 6;
            ret += 5;
        }
        else
        {
            ret += (cur - tar) * 4;
            ret += 5;
        }
        cur = tar;
        n--;
    }
    cout << ret << endl;
}