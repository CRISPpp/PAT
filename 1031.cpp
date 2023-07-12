#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n1 = (s.size() + 2) / 3;
    int n3 = n1;
    int n2 = s.size() - n1 - n3 + 2;
    int idx = 0;
    while (idx < n3)
    {
        string ret = "";
        ret += s[idx];
        if (idx != n3 - 1)
        {
            for (int i = 0; i < n2 - 2; i++)
                ret += " ";
        }
        else
        {
            for (int i = 0; i < n2 - 2; i++)
                ret += s[idx + i + 1];
        }
        ret += s[idx + n2 + 2 * (n1 - idx - 2) + 1];
        cout << ret << endl;
        idx++;
    }
}