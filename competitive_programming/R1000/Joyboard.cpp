// Problem: C. Joyboard
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 3)
    {
        cout << 0 << endl;
    }
    else if (k == 1)
    {
        cout << 1 << endl;
    }
    else if (k == 2)
    {
        cout << min(n, m) + (m - min(n, m)) / n << endl;
    }
    else
    {
        cout << m - min(n, m) - (m - min(n, m)) / n << endl;
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
