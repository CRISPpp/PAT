#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<string, vector<int>> stuToCorse;

    for (int i = 0; i < k; i++)
    {
        int idx, tmpN;
        cin >> idx >> tmpN;
        for (int j = 0; j < tmpN; j++)
        {
            string name;
            cin >> name;
            stuToCorse[name].emplace_back(idx);
        }
    }

    for (int x = 0; x < n; x++)
    {
        string name;
        cin >> name;
        cout << name << " " << stuToCorse[name].size();
        if (stuToCorse[name].size() == 0)
            cout << endl;
        else
            cout << " ";
        sort(stuToCorse[name].begin(), stuToCorse[name].end());
        for (int i = 0; i < stuToCorse[name].size(); i++)
        {
            cout << stuToCorse[name][i];
            if (i == stuToCorse[name].size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}