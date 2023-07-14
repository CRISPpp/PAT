#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 256;

int dp[M][N];

int n, m;

int numsN[N];
int numsM[M];

unordered_map<int, bool> mp;

int main()
{
    int tmp;
    cin >> tmp;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> numsM[i];
        mp[numsM[i]] = true;
    }

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        if (mp.count(k) == 0)
        {
            n--;
            i--;
            continue;
        }
        numsN[i] = k;
    }

    int ret = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (numsM[i] == numsN[j])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j]++;
            }
            ret = max(ret, dp[i][j]);
        }
    }

    cout << ret << endl;
}
