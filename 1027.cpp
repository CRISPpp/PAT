#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string ret = "#";
    string tmp = "";
    map<int, char> mp;
    mp[10] = 'A';
    mp[11] = 'B';
    mp[12] = 'C';
    if (a == 0)
        tmp = "00";
    while (a > 0)
    {
        int nxt = a % 13;
        if (nxt < 10)
            tmp += to_string(nxt);
        else
            tmp += mp[nxt];
        a /= 13;
    }
    if (tmp.size() == 1)
        tmp += '0';
    reverse(tmp.begin(), tmp.end());
    ret += tmp;
    tmp = "";
    if (b == 0)
        tmp = "00";
    while (b > 0)
    {
        int nxt = b % 13;
        if (nxt < 10)
            tmp += to_string(nxt);
        else
            tmp += mp[nxt];
        b /= 13;
    }
    if (tmp.size() == 1)
        tmp += '0';
    reverse(tmp.begin(), tmp.end());
    ret += tmp;
    tmp = "";
    if (c == 0)
        tmp = "00";
    while (c > 0)
    {
        int nxt = c % 13;
        if (nxt < 10)
            tmp += to_string(nxt);
        else
            tmp += mp[nxt];
        c /= 13;
    }
    if (tmp.size() == 1)
        tmp += '0';
    reverse(tmp.begin(), tmp.end());
    ret += tmp;
    cout << ret << endl;
}