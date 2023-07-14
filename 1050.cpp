#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    string ret;
    unordered_map<char, bool> mp;
    for (char c : b)
        mp[c] = true;
    for (char c : a)
    {
        if (mp.count(c) == 0)
            ret += c;
    }
    cout << ret << endl;
}