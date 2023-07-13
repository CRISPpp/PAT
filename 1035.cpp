#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, string> mp;
unordered_map<char, char> tmp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    tmp['1'] = '@';
    tmp['0'] = '%';
    tmp['l'] = 'L';
    tmp['O'] = 'o';
    vector<string> tmps;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        string name;
        string ss;
        bool f = false;
        cin >> name >> s;
        for (char c : s)
        {
            if (tmp.count(c) == 0)
            {
                ss += c;
            }
            else
            {
                f = true;
                ss += tmp[c];
            }
        }
        if (f)
            mp[name] = ss, tmps.emplace_back(name);
    }
    if (mp.size() == 0)
    {
        if (n == 1)
        {
            cout << "There is 1 account and no account is modified" << endl;
        }
        else
        {
            cout << "There are " + to_string(n) << " accounts and no account is modified" << endl;
        }
    }
    else
    {
        cout << mp.size() << endl;
        for (string x : tmps)
        {
            cout << x << " " << mp[x] << endl;
        }
    }
}