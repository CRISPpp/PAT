// 出题人真的是有病，head给个几把-1害老子找这么久的bug
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> getNext;
unordered_map<int, int> getKey;
vector<int> ids;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int headIdx;
    cin >> headIdx;
    for (int i = 0; i < n; i++)
    {
        int curId;
        int curKey;
        int nxtId;
        cin >> curId >> curKey >> nxtId;
        getKey[curId] = curKey;
        if (nxtId != -1)
            getNext[curId] = nxtId;
    }
    if (n == 0)
    {
        printf("0 -1");
        return 0;
    }

    ids.emplace_back(headIdx);
    while (getNext.count(headIdx) != 0)
    {
        headIdx = getNext[headIdx];
        ids.emplace_back(headIdx);
    }

    sort(ids.begin(), ids.end(), [&](int a, int b)
         { return getKey[a] < getKey[b]; });

    printf("%d %05d\n", ids.size(), ids[0]);
    for (int i = 0; i < ids.size() - 1; i++)
    {
        printf("%05d %d %05d\n", ids[i], getKey[ids[i]], ids[i + 1]);
    }
    printf("%05d %d -1\n", ids[ids.size() - 1], getKey[ids[ids.size() - 1]]);
}