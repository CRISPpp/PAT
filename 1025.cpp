#include <bits/stdc++.h>
using namespace std;

const int N = 256;
const int K = 512;
int n;
class Stu
{
public:
    string id;
    int final_rank;
    int local_number;
    int local_rank;
    int score;

    Stu(string i, int l, int s)
    {
        id = i;
        local_number = l;
        local_rank = -1;
        final_rank = -1;
        score = s;
    }
};

vector<Stu> stus[N];

vector<Stu> ret;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        cin >> k;
        cin.get();
        for (int j = 0; j < k; j++)
        {
            string tmp;
            getline(cin, tmp);
            string tmpId = tmp.substr(0, 13);
            int tmpScore = stoi(tmp.substr(14));
            Stu tmpStu(tmpId, i, tmpScore);
            stus[i].emplace_back(tmpStu);
        }
        sort(stus[i].begin(), stus[i].end(), [&](Stu a, Stu b)
             {
            if (a.score != b.score) return a.score > b.score;
            return a.id < b.id; });

        stus[i][0].local_rank = 1;
        ret.emplace_back(stus[i][0]);
        for (int j = 1; j < k; j++)
        {
            if (stus[i][j].score == stus[i][j - 1].score)
                stus[i][j].local_rank = stus[i][j - 1].local_rank;
            else
                stus[i][j].local_rank = j + 1;
            ret.emplace_back(stus[i][j]);
        }
    }

    sort(ret.begin(), ret.end(), [&](Stu a, Stu b)
         {
            if (a.score != b.score) return a.score > b.score;
            return a.id < b.id; });
    ret[0].final_rank = 1;
    for (int j = 1; j < ret.size(); j++)
    {
        if (ret[j].score == ret[j - 1].score)
            ret[j].final_rank = ret[j - 1].final_rank;
        else
            ret[j].final_rank = j + 1;
    }
    cout << ret.size() << endl;
    for (Stu sss : ret)
    {
        cout << sss.id << " " << to_string(sss.final_rank) + " " << to_string(sss.local_number) << " " << to_string(sss.local_rank) << endl;
    }
}