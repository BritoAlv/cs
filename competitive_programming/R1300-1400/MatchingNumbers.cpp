// Problem: C. Matching Numbers
// Contest: Codeforces - Codeforces Round 851 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1788/C
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

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << wp << ((n + i + n / 2) > 2 * n ? (i + n / 2) : (n + i + n / 2)) << endl;
        }
    }
    else
    {
        cout << "No" << endl;
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
