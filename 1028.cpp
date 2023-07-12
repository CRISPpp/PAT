#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
class Stu
{
public:
    string id;
    string name;
    int score;
    Stu(string i, string nn, int s)
    {
        id = i;
        name = nn;
        score = s;
    }
};

vector<Stu> l;

struct cmp
{
    bool operator()(Stu a, Stu b)
    {
        return a.score < b.score;
    }
};

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        int score;
        cin >> a >> b >> score;
        Stu sss(a, b, score);
        l.emplace_back(sss);
    }
    if (c == 1)
    {
        sort(l.begin(), l.end(), [&](Stu a, Stu b)
             { return a.id < b.id; });
    }
    else if (c == 2)
    {
        sort(l.begin(), l.end(), [&](Stu a, Stu b)
             { if(a.name != b.name) return a.name < b.name;
             return a.id < b.id; });
    }
    else
    {
        sort(l.begin(), l.end(), [&](Stu a, Stu b)
             {if(a.score != b.score) return a.score < b.score; 
             return a.id < b.id; });
    }
    for (int i = 0; i < l.size(); i++)
    {
        cout << l[i].id << " " << l[i].name << " " << l[i].score << endl;
    }
}