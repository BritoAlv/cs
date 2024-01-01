// Problem: C. Parity Shuffle Sorting
// Contest: Codeforces - Codeforces Round 821 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1733/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int a[100000];

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<pair<int, int>> ops;
        ops.pb({1, n});
        if ((a[0] + a[n - 1]) % 2 == 1)
        {
            a[n - 1] = a[0];
        }
        else
        {
            a[0] = a[n - 1];
        }
        for (int i = 1; i <= n - 2; i++)
        {
            if ((a[i] + a[0]) % 2 == 1)
            {
                ops.pb({1, i + 1});
            }
            else
            {
                ops.pb({i + 1, n});
            }
        }
        cout << ops.size() << endl;
        for (auto x : ops)
        {
            cout << x.first << wp << x.second << endl;
        }
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
