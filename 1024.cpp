#include <bits/stdc++.h>
using namespace std;

string myAdd(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.end());
    string ret = "";
    int c = 0;
    int idxA = 0, idxB = 0;
    while (idxA < a.size() && idxB < b.size())
    {
        int nxt = a[idxA++] - '0' + b[idxB++] - '0' + c;
        c = nxt / 10;
        nxt %= 10;
        ret += nxt + '0';
    }
    while (idxA < a.size())
    {
        int nxt = a[idxA++] - '0' + c;
        c = nxt / 10;
        nxt %= 10;
        ret += nxt + '0';
    }
    while (idxB < b.size())
    {
        int nxt = b[idxB++] - '0' + c;
        c = nxt / 10;
        nxt %= 10;
        ret += nxt + '0';
    }
    if (c > 0)
        ret += c + '0';
    reverse(ret.begin(), ret.end());
    return ret;
}

bool f(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;

    if (f(n))
    {
        cout << n << endl;
        cout << 0 << endl;
        return 0;
    }
    string nxt = n;
    reverse(nxt.begin(), nxt.end());
    int i = 0;
    for (; i < k; i++)
    {
        n = myAdd(n, nxt);
        if (f(n))
        {
            i++;
            break;
        }
        nxt = n;
        reverse(nxt.begin(), nxt.end());
    }
    cout << n << endl;
    cout << i << endl;
}