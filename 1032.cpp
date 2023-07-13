#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
string first, second;
class Node
{
public:
    string id;
    string nxtId;
    string data;
    Node *nxt;
    Node(string id)
    {
        this->id = id;
        this->nxtId = -1;
        this->data = "";
        this->nxt = nullptr;
    }
};

unordered_map<string, Node *> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> first >> second >> n;
    for (int i = 0; i < n; i++)
    {
        string id, data, nxtId;
        cin >> id >> data >> nxtId;
        if (mp.count(id) == 0)
        {
            Node *node = new Node(id);
            mp[id] = node;
        }
        mp[id]->data = data;
        if (mp.count(nxtId) == 0)
        {
            Node *nxtNode = new Node(nxtId);
            mp[nxtId] = nxtNode;
        }
        mp[id]->nxtId = nxtId;
        mp[id]->nxt = mp[nxtId];
    }

    if (mp.count(first) == 0 || mp.count(second) == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    Node *firstNode = mp[first];
    Node *secondNode = mp[second];

    unordered_map<Node *, bool> vis;
    while (firstNode != nullptr)
    {
        vis[firstNode] = true;
        firstNode = firstNode->nxt;
    }

    while (secondNode != nullptr)
    {
        if (vis[secondNode])
        {
            cout << secondNode->id << endl;
            return 0;
        }
        secondNode = secondNode->nxt;
    }

    cout << -1 << endl;
}
