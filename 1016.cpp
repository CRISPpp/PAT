// 太傻逼了大模拟，不写了妈的
#include <bits/stdc++.h>
using namespace std;

int cost[24];
int n;
map<string, vector<int>> timeOn;
map<string, vector<int>> timeOff;
map<string, string> mon;

int cal(int t, int e)
{
    int ret = 0;
    int day = 0;
    int hour = 0;
    int minn = 0;
    while (t > 0)
    {
        if (t > 24 * 60)
        {
            day += t / (24 * 60);
            t %= (24 * 60);
        }
        else if (t > 60)
        {
            hour += t / 60;
            t %= 60;
        }
        else
        {
            minn = t;
            t = 0;
        }
    }

    int day2 = 0;
    int hour2 = 0;
    int minn2 = 0;
    while (e > 0)
    {
        if (e > 24 * 60)
        {
            day2 += e / (24 * 60);
            e %= (24 * 60);
        }
        else if (e > 60)
        {
            hour2 += e / 60;
            e %= 60;
        }
        else
        {
            minn2 = e;
            e = 0;
        }
    }

    while (day != day2)
    {
        ret += cost[hour] * (60 - minn);
        hour++;
        minn = 0;
        while (hour < 24)
        {
            ret += 60 * cost[hour];
            hour++;
        }
        hour = 0;
        day++;
    }

    while (hour != hour2)
    {
        ret += cost[hour] * (60 - minn);
        hour++;
        minn = 0;
    }

    ret += cost[hour] * (minn2 - minn);
    return ret;
};

string toFormat(int t)
{
    int day = 0;
    int hour = 0;
    int minn = 0;
    while (t > 0)
    {
        if (t > 24 * 60)
        {
            day += t / (24 * 60);
            t %= (24 * 60);
        }
        else if (t > 60)
        {
            hour += t / 60;
            t %= 60;
        }
        else
        {
            minn = t;
            t = 0;
        }
    }
    string ret = "";
    if (day < 10)
        ret += "0";
    ret += to_string(day);
    ret += ":";
    if (hour < 10)
        ret += "0";
    ret += to_string(hour);
    ret += ":";
    if (minn < 10)
        ret += "0";
    ret += to_string(minn);
    return ret;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 24; i++)
    {
        int tmpCost;
        cin >> tmpCost;
        cost[i] = tmpCost;
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        string t;
        string online;
        cin >> name >> t >> online;
        int curTime = stoi(t.substr(9, 2));
        curTime += stoi(t.substr(6, 2)) * 60;
        curTime += stoi(t.substr(3, 2)) * 24 * 60;
        mon[name] = t.substr(0, 2);
        if (online == "on-line")
        {
            timeOn[name].emplace_back(curTime);
        }
        else
        {
            timeOff[name].emplace_back(curTime);
        }
    }

    priority_queue<string, vector<string>, greater<string>> retQ;
    for (auto &a : timeOn)
    {
        retQ.push(a.first);
    }

    while (retQ.size() > 0)
    {
        string curName = retQ.top();
        retQ.pop();
        sort(timeOn[curName].begin(), timeOn[curName].end());
        sort(timeOff[curName].begin(), timeOff[curName].end());

        bool flag = false;
        int totalCost = 0;
        int idx = 0;
        while (idx < timeOff[curName].size() && timeOn[curName].size() > 0)
        {
            int curCost = 0;

            auto endTime = timeOff[curName][idx];

            auto it = lower_bound(timeOn[curName].begin(), timeOn[curName].end(), endTime);
            if (it == timeOn[curName].begin())
            {
                idx++;
                continue;
            }
            it--;
            if (*it > endTime)
            {
                idx++;
                continue;
            }
            if (!flag)
            {
                flag = true;
                cout << curName << " " << mon[curName] << endl;
            }
            auto startTime = *it;
            timeOn[curName].erase(it);

            curCost = cal(startTime, endTime);
            totalCost += curCost;
            cout << toFormat(startTime) << " " << toFormat(endTime) << " " << to_string(endTime - startTime) << " "
                 << "$" << fixed << setprecision(2) << ((double)curCost) / 100 << endl;
            idx++;
        }
        cout << "Total amount: "
             << "$" << fixed << setprecision(2) << ((double)totalCost) / 100 << endl;
    }
}