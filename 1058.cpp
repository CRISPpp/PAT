#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    string a1 = "", a2 = "", a3 = "", b1 = "", b2 = "", b3 = "";
    int idx1 = 0, idx2 = 0;
    while (a[idx1] != '.')
        a1 += a[idx1++];
    idx1++;
    while (a[idx1] != '.')
        a2 += a[idx1++];
    idx1++;
    while (idx1 < a.size())
        a3 += a[idx1++];

    while (b[idx2] != '.')
        b1 += b[idx2++];
    idx2++;
    while (b[idx2] != '.')
        b2 += b[idx2++];
    idx2++;
    while (idx2 < b.size())
        b3 += b[idx2++];
    int c = 0;
    int c3 = stoi(a3) + stoi(b3);
    c = c3 / 29;
    c3 %= 29;
    int c2 = stoi(a2) + stoi(b2) + c;
    c = c2 / 17;
    c2 %= 17;
    int c1 = c + stoi(a1) + stoi(b1);
    cout << to_string(c1) + "." + to_string(c2) + "." + to_string(c3) << endl;
}