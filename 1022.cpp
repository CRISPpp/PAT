#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
unordered_map<string, set<string>> author;
unordered_map<string, set<string>> tittle;
unordered_map<string, set<string>> keyWord;
unordered_map<string, set<string>> publisher;
unordered_map<string, set<string>> year;
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string id;
        cin >> id;
        cin.get();
        string t;
        getline(cin, t);
        tittle[t].insert(id);
        string a;
        getline(cin, a);
        author[a].insert(id);
        string k;
        getline(cin, k);
        string kTmp;
        int idx = 0;
        while (idx < k.size())
        {
            if (k[idx] == ' ')
            {
                if (kTmp.size() != 0)
                {
                    keyWord[kTmp].insert(id);
                    kTmp = "";
                }
                while (idx < k.size() && k[idx] == ' ')
                    idx++;
            }
            else
            {
                kTmp += k[idx++];
            }
        }
        if (kTmp.size() > 0)
            keyWord[kTmp].insert(id);
        string p;
        getline(cin, p);
        publisher[p].insert(id);
        string y;
        cin >> y;
        year[y].insert(id);
    }

    int m;
    cin >> m;
    cin.get();
    for (int i = 0; i < m; i++)
    {
        string tmp;
        getline(cin, tmp);
        cout << tmp << endl;
        string tar = tmp.substr(3, tmp.size() - 3);
        set<string> ret;

        if ((tmp[0] - '0') == 1)
        {
            ret = tittle[tar];
        }
        else if ((tmp[0] - '0') == 2)
        {
            ret = author[tar];
        }
        else if ((tmp[0] - '0') == 3)
        {
            ret = keyWord[tar];
        }
        else if ((tmp[0] - '0') == 4)
        {
            ret = publisher[tar];
        }
        else if ((tmp[0] - '0') == 5)
        {
            ret = year[tar];
        }

        if (ret.size() == 0)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            for (string sss : ret)
            {
                cout << sss << endl;
            }
        }
    }
}