// Problem: B. Laura and Operations
// Contest: Codeforces - Codeforces Round 911 (Div. 2)
// URL: https://codeforces.com/contest/1900/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (b % 2 == c % 2) << wp << (a % 2 == c % 2) << wp << (a % 2 == b % 2) << endl;
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