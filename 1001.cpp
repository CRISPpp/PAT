#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a = 0;
    long long b = 0;
    cin >> a >> b;
    a += b;

    string tmp = to_string(a);

    int cnt = 0;

    string ret = "";

    for (int i = tmp.size() - 1, down = (tmp[0] == '-' ? 1 : 0); i >= down; i--)
    {
        if (tmp[i] >= '0' && tmp[i] <= '9')
        {
            ret += tmp[i];
            cnt++;
            if (cnt == 3 && i != down)
            {
                ret += ',';
                cnt = 0;
            }
        }
    }
    if (tmp[0] == '-')
        ret += '-';

    reverse(ret.begin(), ret.end());

    cout << ret << endl;
    return 0;
}