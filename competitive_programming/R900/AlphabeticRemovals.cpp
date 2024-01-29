// Problem: C. Alphabetic Removals
// Contest: Codeforces - Codeforces Round 490 (Div. 3)
// URL: https://codeforces.com/contest/999/problem/C
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
    int n, k;
    cin >> n >> k;
    vector<pair<char, int>> a;
    forn
    {
        char t;
        cin >> t;
        a.pb({t, i});
    }
    sort(a.begin(), a.end());
    vector<pair<int, char>> rem;
    for (int i = k; i < n; i++)
    {
        rem.pb({a[i].second, a[i].first});
    }
    sort(rem.begin(), rem.end());
    for (auto x : rem)
    {
        cout << x.second;
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
