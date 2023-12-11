// Problem: B. Binary Cafe
// Contest: Codeforces - Codeforces Round 878 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1840/B
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
    int n, k;
    cin >> n >> k;
    if (k >= 31)
    {
        cout << n + 1 << endl;
    }
    else
    {
        cout << min(n + 1, (1 << k)) << endl;
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
