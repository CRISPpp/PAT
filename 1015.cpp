#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool isPrime[N];
int n, d;

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (isPrime[i])
        {
            for (int j = i + i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int toMyDecimal(string tmp, int radix)
{
    int base = 1;
    int ret = 0;
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        ret += base * (tmp[i] - '0');
        base *= radix;
    }
    return ret;
}

string getReverseRadix(int num, int radix)
{
    if (num == 0)
        return "0";
    string ret = "";
    while (num > 0)
    {
        ret += to_string(num % radix);
        num /= radix;
    }
    return ret;
}

bool myIsPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    while (cin >> n)
    {
        if (n < 0)
        {
            break;
        }
        cin >> d;
        if (!isPrime[n])
        {
            cout << "No" << endl;
            continue;
        }
        if (!isPrime[toMyDecimal(getReverseRadix(n, d), d)])
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
}