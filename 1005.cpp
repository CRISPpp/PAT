#include <bits/stdc++.h>
using namespace std;

int main()
{
    string mark[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string n;
    cin >> n;
    if (n == "0")
    {
        cout << mark[0] << endl;
        return 0;
    }
    int t = 0;
    for (char c : n)
    {
        t += (c - '0');
    }
    string tmp = to_string(t);
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << mark[tmp[i] - '0'];
        if (i == tmp.size() - 1)
            cout << endl;
        else
            cout << " ";
    }
}