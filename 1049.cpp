#include <bits/stdc++.h>
using namespace std;
int n;
string num;
vector<vector<int>> dp;

int numDp(int idx, int cnt, int isLimit)
{
    if (idx == num.size())
        return cnt;
    if (!isLimit && dp[idx][cnt] > 0)
        return dp[idx][cnt];
    int up = isLimit ? (num[idx] - '0') : 9;
    int res = 0;
    for (int i = 0; i <= up; i++)
    {
        res += numDp(idx + 1, cnt + (i == 1), isLimit && i == up);
    }
    if (!isLimit)
        dp[idx][cnt] = res;
    return res;
}

int main()
{
    cin >> n;
    num = to_string(n);
    dp.resize(num.size(), vector<int>(num.size(), -1));
    cout << numDp(0, 0, true) << endl;
}