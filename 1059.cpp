#include <bits/stdc++.h>
using namespace std;

bool isPrime(int idx)
{
    for (int i = 2; i <= sqrt(i); i++)
    {
        if (idx % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << n << "=";
    if (n == 1)
        cout << "1";
    while (n > 1)
    {
        int idx = 2;
        while (n % idx != 0)
        {
            idx++;
            while (!isPrime(idx))
                idx++;
        }
        int cnt = 0;
        while (n % idx == 0)
        {
            cnt++;
            n /= idx;
        }
        cout << idx;
        if (cnt > 1)
            cout << "^" << cnt;
        if (n != 1)
            cout << "*";
    }
}