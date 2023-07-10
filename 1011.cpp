#include <bits/stdc++.h>
using namespace std;

int main()
{
    char mark[3] = {'W', 'T', 'L'};
    double ret = 0.65;
    for (int i = 0; i < 3; i++)
    {
        int pos = -1;
        double maxVal = -1;
        for (int j = 0; j < 3; j++)
        {
            double tmp;
            cin >> tmp;
            if (tmp > maxVal)
            {
                pos = j;
                maxVal = tmp;
            }
        }
        cout << mark[pos] << " ";
        ret *= maxVal;
    }
    cout << fixed << setprecision(2) << (ret - 1) * 2 << endl;
}