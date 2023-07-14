#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    map<int, int> mp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }

    for (auto &p : mp)
    {
        int tar = m - p.first;
        if (tar < p.first)
            break;
        mp[p.first]--;
        if (mp.count(tar) != 0 && mp[tar] > 0)
        {
            cout << p.first << " " << tar << endl;
            return 0;
        }
    }

    cout << "No Solution\n";
}