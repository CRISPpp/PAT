#include <bits/stdc++.h>
using namespace std;

const int N = 1024;

bool dp[N][N];

int main()
{
    string s;
    getline(cin, s);
    int n = s.size();
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
        dp[i][1] = true;
        ret = 1;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            if (s[i] == s[i + len - 1] && dp[i + 1][len - 2])
            {
                dp[i][len] = true;
                ret = len;
            }
        }
    }
    cout << ret << endl;
}