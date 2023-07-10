#include <bits/stdc++.h>
using namespace std;

long long getNum(string s, long long radix)
{
    long long ret = 0;
    long long tmp = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        long long num = isdigit(s[i]) ? (s[i] - '0') : (s[i] - 'a' + 10);
        num *= tmp;
        ret += num;
        tmp *= radix;
    }
    return ret;
}

int main()
{
    string n1, n2;
    int tag, ra;
    cin >> n1 >> n2 >> tag >> ra;
    if (tag == 2)
    {
        string tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    int limit = 2;
    long long num1 = getNum(n1, ra);
    for (int i = 0; i < n2.size(); i++)
    {
        int tmp = (isdigit(n2[i]) ? (n2[i] - '0') : (n2[i] - 'a' + 10));
        tmp++;
        limit = max(tmp, limit);
    }

    long long l = limit, r = max((long long)limit, num1);
    bool f = false;

    while (l <= r)
    {
        long long m = (r - l) / 2 + l;
        long long num2 = getNum(n2, m);
        if (num2 < 0 || num2 > num1)
        {
            r = m - 1;
        }
        else if (num2 < num1)
        {
            l = m + 1;
        }
        else if (num1 == num2)
        {
            f = true;
            r = m - 1;
        }
    }

    if (f)
    {
        cout << l << endl;
        return 0;
    }

    cout << "Impossible" << endl;
}