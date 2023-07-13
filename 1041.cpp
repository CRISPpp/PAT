#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> cnt;
vector<int> q;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        q.emplace_back(tmp);
        cnt[tmp]++;
    }

    for (int i : q)
    {
        if (cnt[i] == 1)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "None\n";
}