#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    int idxA = 0, idxB = 0;
    int cntA = 0, cntB = 0;
    string nA, nB;
    while (idxA < a.size() && a[idxA] == '0')
        idxA++;
    if (a[idxA] == '.')
    {
        idxA++;
        while (idxA < a.size() && a[idxA] == '0')
        {
            idxA++;
            cntA--;
        }
        while (idxA < a.size())
            nA += a[idxA++];
    }
    else
    {
        while (idxA < a.size() && a[idxA] != '.')
        {
            cntA++;
            nA += a[idxA++];
        }
        idxA++;
        while (idxA < a.size())
            nA += a[idxA++];
    }
    while (nA.size() < n)
        nA += '0';
    nA = nA.substr(0, n);

    while (idxB < b.size() && b[idxB] == '0')
        idxB++;
    if (b[idxB] == '.')
    {
        idxB++;
        while (idxB < b.size() && b[idxB] == '0')
        {
            idxB++;
            cntB--;
        }
        while (idxB < b.size())
            nB += b[idxB++];
    }
    else
    {
        while (idxB < b.size() && b[idxB] != '.')
        {
            cntB++;
            nB += b[idxB++];
        }
        idxB++;
        while (idxB < b.size())
            nB += b[idxB++];
    }
    while (nB.size() < n)
        nB += '0';
    nB = nB.substr(0, n);

    if (nA == nB && cntA == cntB)
    {
        cout << "YES "
             << "0." << nA << "*10^" << to_string(cntA) << endl;
    }
    else
    {
        cout << "NO "
             << "0." << nA << "*10^" << to_string(cntA) << " "
             << "0." << nB << "*10^" << to_string(cntB) << endl;
    }
}