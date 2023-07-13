#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> ss;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ss.emplace_back(s);
    }
    sort(ss.begin(), ss.end(), [&](string &a, string &b)
         { return a + b < b + a; });

    string ret;

    for (int i = 0; i < ss.size(); i++)
        ret += ss[i];

    int idx = 0;
    while (idx < ret.size() && ret[idx] == '0')
        idx++;
    ret = ret.substr(idx);
    if (ret.size() == 0)
        cout << "0" << endl;
    else
        cout << ret << endl;
}