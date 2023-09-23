#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &m, &n);
    unordered_map<int, int> cnt;
    int ret = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            cnt[tmp]++;
        }
    }
    for (auto a : cnt)
    {
        if (ret == -1 || cnt[ret] < a.second)
        {
            ret = a.first;
        }
    }
    printf("%d\n", ret);
}