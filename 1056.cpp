// 傻逼题目,题干写的很傻逼
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_NP 1000
struct Mouse
{
    int weight;
    int rank;
} mouses[MAX_NP];
int main()
{
    int NP, NG;
    queue<int> q;
    scanf("%d %d", &NP, &NG);
    for (int i = 0; i < NP; i++)
    {
        scanf("%d", &mouses[i].weight);
    }
    for (int i = 0, t; i < NP; i++)
    {
        scanf("%d", &t);
        q.push(t);
    }

    // cnt为该轮老鼠数量，group为组数，maxWeight和maxIndex用于暂存某组中最重的老鼠的重量和下标
    int group, cnt, maxWeight, maxIndex;
    while ((cnt = (int)q.size()) > 1)
    {
        group = cnt / NG + (cnt % NG == 0 ? 0 : 1);
        for (int i = 0; i < group; i++)
        {
            maxWeight = -1;
            maxIndex = -1;
            for (int j = 0; j < NG && i * NG + j < cnt; j++)
            {
                mouses[q.front()].rank = group + 1;
                if (mouses[q.front()].weight > maxWeight)
                {
                    maxIndex = q.front();
                    maxWeight = mouses[q.front()].weight;
                }
                q.pop();
            }
            q.push(maxIndex);
        }
    }
    // 将最后一只老鼠标记为第一名
    mouses[q.front()].rank = 1;

    // 输出结果
    printf("%d", mouses[0].rank);
    for (int i = 1; i < NP; i++)
    {
        printf(" %d", mouses[i].rank);
    }
    return 0;
}
