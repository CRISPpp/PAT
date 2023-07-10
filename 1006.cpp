#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int timeIn = -1;
    int timeOut = -1;
    string ret1 = "";
    string ret2 = "";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string id;
        cin >> id;
        string inTime;
        cin >> inTime;
        string outTime;
        cin >> outTime;
        int timeOne = stoi(inTime.substr(0, 2)) * 3600 + stoi(inTime.substr(3, 2)) * 60 + stoi(inTime.substr(6, 2));
        if (timeIn == -1 || (timeIn > timeOne))
        {
            timeIn = timeOne;
            ret1 = id;
        }

        int timeTwo = stoi(outTime.substr(0, 2)) * 3600 + stoi(outTime.substr(3, 2)) * 60 + stoi(outTime.substr(6, 2));
        if (timeOut == -1 || (timeOut < timeTwo))
        {
            timeOut = timeTwo;
            ret2 = id;
        }
    }
    cout << ret1 << " " << ret2 << endl;
}