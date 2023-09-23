// 傻逼题干
#include <bits/stdc++.h>
using namespace std;
string Day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int idx1 = 0, idx2 = 0;
    bool f = false;
    int cur = 0;
    int h = 0;
    int minn = 0;
    while (idx1 < a.size() && idx2 < b.size())
    {
        if (a[idx1] == b[idx2])
        {
            if (!f && a[idx1] >= 'A' && a[idx1] <= 'G')
            {
                f = true;
                cur = a[idx1] - 'A';
            }
            else if (f && ((a[idx1] >= '0' && a[idx1] <= '9') || (a[idx1] >= 'A' && a[idx1] <= 'N')))
            {
                if (a[idx1] >= '0' && a[idx1] <= '9')
                {
                    h = a[idx1] - '0';
                }
                else
                {
                    h = 10 + a[idx1] - 'A';
                }
                break;
            }
        }
        idx1++;
        idx2++;
    }
    int idx3 = 0, idx4 = 0;
    while (idx3 < c.size() && idx4 < d.size() && !(c[idx3] == d[idx4] && isalpha(c[idx3]) && isalpha(d[idx4])))
    {
        idx3++;
        idx4++;
    }
    minn = idx3;
    string ret;
    ret += Day[cur];
    ret += " ";
    if (h < 10)
        ret += '0';
    ret += to_string(h);
    ret += ":";
    if (minn < 10)
        ret += '0';
    ret += to_string(minn);
    cout << ret << endl;
}