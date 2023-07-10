#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int nums[10010];
    int sum[10010];
    int s = 0;
    int curMax = 0;
    int ret0 = 0;
    int ret1 = 0;
    int tmpRet0 = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        nums[s++] = tmp;
        if (i == 0)
        {
            sum[0] = tmp;
            curMax = tmp;
        }
        else
        {
            if (sum[i - 1] < 0)
            {
                sum[i] = tmp;
                tmpRet0 = i;
                if (sum[i] > curMax)
                {
                    ret0 = i;
                    ret1 = i;
                    curMax = sum[i];
                }
            }
            else
            {
                sum[i] = tmp + sum[i - 1];
                if (sum[i] > curMax)
                {
                    curMax = sum[i];
                    ret1 = i;
                    ret0 = tmpRet0;
                }
            }
        }
    }
    if (curMax < 0)
    {
        cout << 0 << " " << nums[0] << " " << nums[s - 1] << endl;
        return 0;
    }
    cout << curMax << " " << nums[ret0] << " " << nums[ret1] << endl;
}