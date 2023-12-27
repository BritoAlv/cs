// Problem: A1. Make Nonzero Sum (easy version)
// Contest: Codeforces - Codeforces Round 829 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1753/A1
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

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        vector<pair<int, int>> partitions;
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] == a[i + 1])
            {
                partitions.pb({i + 1, i + 2});
            }
            else
            {
                partitions.pb({i + 1, i + 1});
                partitions.pb({i + 2, i + 2});
            }
        }
        cout << partitions.size() << endl;
        for (auto x : partitions)
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