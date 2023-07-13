#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string male[3];
    string female[3];

    for (int i = 0; i < n; i++)
    {
        string a, b, c;
        int d;
        cin >> a >> b >> c >> d;
        if (b == "M")
        {
            if (male[2].size() == 0 || (stoi(male[2]) > d))
            {
                male[2] = to_string(d);
                male[0] = a;
                male[1] = c;
            }
        }
        else
        {
            if (female[2].size() == 0 || (stoi(female[2]) < d))
            {
                female[2] = to_string(d);
                female[0] = a;
                female[1] = c;
            }
        }
    }

    if (female[2].size() == 0)
        cout << "Absent\n";
    else
        cout << female[0] << " " << female[1] << endl;
    if (male[2].size() == 0)
        cout << "Absent\n";
    else
        cout << male[0] << " " << male[1] << endl;
    if (female[2].size() == 0 || male[2].size() == 0)
        cout << "NA\n";
    else
        cout << (stoi(female[2]) - stoi(male[2])) << endl;
}