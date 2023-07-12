#include <bits/stdc++.h>
using namespace std;

const int N = 32;
int origin[N];
int doubleNum[N];

int main()
{
    string s;
    cin >> s;
    int idx = 0;
    int c = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        origin[idx] = s[i] - '0';
        int nxt = origin[idx] * 2 + c;
        c = nxt / 10;
        nxt %= 10;
        doubleNum[idx] = nxt;
        idx++;
    }
    if (c > 0)
    {
        doubleNum[idx++] = c;
        cout << "No" << endl;
    }
    else
    {
        map<int, int> c1;
        for (int i = 0; i < idx; i++)
        {
            c1[origin[i]]++;
        }
        bool f = true;
        for (int i = 0; i < idx; i++)
        {
            if (c1.count(doubleNum[i]) == 0)
            {
                f = false;
                break;
            }
            c1[doubleNum[i]]--;
            if (c1[doubleNum[i]] == 0)
                c1.erase(doubleNum[i]);
        }
        if (c1.size() != 0)
            f = false;
        if (f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    for (int i = idx - 1; i >= 0; i--)
        cout << doubleNum[i];
    cout << endl;
}