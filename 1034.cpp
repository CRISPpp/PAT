#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
unordered_map<string, int> idMap;
string name[N * 2];
int p[N * 2];
int weight[N * 2];
int n, k, nameIdx = 0;

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < N * 2; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        string name1, name2;
        int time;
        cin >> name1 >> name2 >> time;
        if (idMap.count(name1) == 0)
        {
            name[nameIdx] = name1;
            idMap[name1] = nameIdx;
            nameIdx++;
        }

        if (idMap.count(name2) == 0)
        {
            name[nameIdx] = name2;
            idMap[name2] = nameIdx;
            nameIdx++;
        }

        int idx1 = idMap[name1];
        int idx2 = idMap[name2];
        weight[idx1] += time;
        weight[idx2] += time;
        p[find(idx1)] = find(idx2);
    }
    vector<int> tmpHead;
    unordered_map<string, int> headToTmpHead;
    vector<string> heads;
    unordered_map<int, vector<int>> member;
    unordered_map<int, int> allK;
    for (int i = 0; i < nameIdx; i++)
    {
        member[find(i)].emplace_back(i);
        allK[find(i)] += weight[i];
    }

    for (auto it : member)
    {
        if (it.second.size() > 2 && allK[it.first] > k * 2)
        {
            tmpHead.emplace_back(it.first);
        }
    }

    for (int i : tmpHead)
    {
        int maxIdx = -1;
        for (int j : member[i])
        {
            if (maxIdx == -1 || weight[maxIdx] < weight[j])
                maxIdx = j;
        }
        heads.emplace_back(name[maxIdx]);
        headToTmpHead[name[maxIdx]] = i;
    }

    sort(heads.begin(), heads.end());
    cout << heads.size() << endl;
    for (string sss : heads)
    {
        cout << sss << " " << member[headToTmpHead[sss]].size() << endl;
    }
}