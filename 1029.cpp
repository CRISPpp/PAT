#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n1, n2;
long long nums1[N];
long long nums2[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        long long tmp;
        cin >> tmp;
        nums1[i] = tmp;
    }

    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        long long tmp;
        cin >> tmp;
        nums2[i] = tmp;
    }

    int n = n1 + n2;
    int tar = (n + 1) / 2;
    int cur = 1;
    int idx1 = 0, idx2 = 0;
    sort(nums1, nums1 + n1);
    sort(nums2, nums2 + n2);

    while (idx1 < n1 && idx2 < n2)
    {
        bool f1 = nums1[idx1] < nums2[idx2];
        long long curVal = min(nums1[idx1], nums2[idx2]);
        if (cur == tar)
        {
            cout << curVal << endl;
            return 0;
        }
        if (f1)
            idx1++;
        else
            idx2++;
        cur++;
    }
    while (idx1 < n1)
    {
        long long curVal = nums1[idx1];
        if (cur == tar)
        {
            cout << curVal << endl;
            return 0;
        }
        idx1++;
        cur++;
    }
    while (idx2 < n2)
    {
        long long curVal = nums2[idx2];
        if (cur == tar)
        {
            cout << curVal << endl;
            return 0;
        }
        cur++;
        idx2++;
    }
}