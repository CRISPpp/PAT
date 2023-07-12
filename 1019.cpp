#include <bits/stdc++.h>
using namespace std;
vector<string> toRadix(long long num, long long base)
{
    vector<string> ret;
    if (num == 0)
        return {0};

    while (num > 0)
    {
        ret.emplace_back(to_string(num % base));
        num /= base;
    }
    return ret;
}
int main()
{
    long long n, base;
    cin >> n >> base;
    vector<string> tmp = toRadix(n, base);
    int l = 0, r = tmp.size() - 1;
    bool f = true;
    while (l < r)
    {
        if (tmp[l++] != tmp[r--])
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        cout << tmp[i];
        if (i == 0)
            cout << endl;
        else
            cout << " ";
    }
}