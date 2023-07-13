#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    vector<long long> c1, c2;
    long long ret = 0;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        long long tmp;
        cin >> tmp;
        c1.emplace_back(tmp);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        long long tmp;
        cin >> tmp;
        c2.emplace_back(tmp);
    }

    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());

    int l1 = 0, r1 = n1 - 1, l2 = 0, r2 = n2 - 1;
    while (l1 < n1 && l2 < n2 && c1[l1] < 0 && c2[l2] < 0)
    {
        ret += c1[l1++] * c2[l2++];
    }

    while (r1 >= 0 && r2 >= 0 && c1[r1] > 0 && c2[r2] > 0)
    {
        ret += c1[r1--] * c2[r2--];
    }

    cout << ret << endl;
}