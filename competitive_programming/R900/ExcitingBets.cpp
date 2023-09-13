// Problem: A. Exciting Bets
// Contest: Codeforces - Codeforces Round 730 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1543/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: mcd properties
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    long long a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << wp << 0 << endl;
    }
    else
    {
        if (a < b)
        {
            cout << (b - a) << wp;
            // what's the minimal number m such that:
            // a+m, b+m are both divisible by (b-a)
            // a-m, b-m are both divisible by (b-a)
            cout << min(b % (b - a), (b - a) * (b / (b - a) + 1) - b) << endl;
        }
        else
        {
            cout << (a - b) << wp;
            cout << min(a % (a - b), (a - b) * (a / (a - b) + 1) - a) << endl;
        }
    }
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
