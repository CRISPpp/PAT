#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int nums[1024];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;
    while (k--)
    {
        stack<int> tmp;
        bool f = true;
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        int idx = 1;
        for (int i = 0; i < n && f; i++)
        {
            while (tmp.size() == 0 || (tmp.size() > 0 && tmp.top() != nums[i]))
            {
                tmp.push(idx++);
                if (tmp.size() > m)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                while (i < n && tmp.size() > 0 && tmp.top() == nums[i])
                {
                    tmp.pop();
                    i++;
                }
                i--;
            }
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}