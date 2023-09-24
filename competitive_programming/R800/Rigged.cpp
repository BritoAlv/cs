// Problem: A. Rigged!
// Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1879/problem/0
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
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
    int n;
    cin >> n;
    int pw, pe;
    cin >> pw >> pe;
    bool possible = true;
    while (n > 1)
    {
        int a, b;
        cin >> a >> b;
        if (a >= pw && b >= pe)
        {
            possible = false;
        }
        n--;
    }
    if (possible)
    {
        cout << pw << endl;
    }
    else
    {
        cout << -1 << endl;
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
