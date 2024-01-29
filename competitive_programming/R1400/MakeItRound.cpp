// Problem: D. Make It Round
// Contest: Codeforces - Codeforces Round  834 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1759/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

ull n, m;

ull exp(int base, int exp)
{
    ull ans = 1;
    for (int i = 1; i <= exp; i++)
    {
        ans *= base;
        if (ans > m)
        {
            return ans;
        }
    }
    return ans;
}

int get_exp(ull n, int d)
{
    ull copy = n;
    int ans = 0;
    while (copy % d == 0)
    {
        copy /= d;
        ans++;
    }
    return ans;
}

void Solve()
{
    cin >> n >> m;
    int exp2n = get_exp(n, 2);
    int exp5n = get_exp(n, 5);
    ull actual = n;
    actual *= m;
    int act_z = get_exp(actual, 10);
    int exp2 = get_exp(actual, 2);
    int exp5 = get_exp(actual, 5);
    for (int exp_2 = 0; exp_2 < 32; exp_2++)
    {
        for (int exp_5 = 0; exp_5 < 32; exp_5++)
        {
            if (exp(2, exp_2) * exp(5, exp_5) <= m)
            {
                if (min(exp_2 + exp2n, exp_5 + exp5n) > act_z)
                {
                    act_z = min(exp_2 + exp2n, exp_5 + exp5n);
                    exp2 = exp_2;
                    exp5 = exp_5;
                }
                else if (min(exp_2 + exp2n, exp_5 + exp5n) == act_z)
                {
                    exp2 = min(exp_2, exp2);
                    exp5 = min(exp_5, exp5);
                }
            }
        }
    }
    if ((m / (exp(2, exp2) * exp(5, exp5))) == 0)
    {
        cout << n * m << endl;
    }
    else
    {
        cout << n * (m / (exp(2, exp2) * exp(5, exp5))) * (exp(2, exp2) * exp(5, exp5)) << endl;
    }

    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}