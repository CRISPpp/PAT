#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

class Node
{
public:
    string name;
    int age;
    int worth;
    Node(string name, int age, int worth)
    {
        this->name = name;
        this->age = age;
        this->worth = worth;
    }
};

Node *nodes[N];
int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        string name;
        int age, worth;
        cin >> name;
        scanf("%d %d", &age, &worth);
        nodes[i] = new Node(name, age, worth);
    }

    sort(nodes, nodes + n, [&](Node *a, Node *b)
         {
        if (a -> worth != b -> worth) return a -> worth > b -> worth;
        if (a -> age != b -> age) return a -> age < b -> age;
        return a -> name < b -> name; });

    for (int i = 1; i <= k; i++)
    {
        int m, mmin, mmax;
        scanf("%d %d %d", &m, &mmin, &mmax);
        printf("Case #%d:\n", i);
        int cnt = 0;
        int idx = 0;
        while (cnt < m && idx < n)
        {
            if (nodes[idx]->age >= mmin && nodes[idx]->age <= mmax)
            {
                printf("%s %d %d\n", nodes[idx]->name.c_str(), nodes[idx]->age, nodes[idx]->worth);
                cnt++;
            }
            idx++;
        }
        if (cnt == 0)
            printf("None\n");
    }
}