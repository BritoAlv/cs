// Problem: C. Even Picture
// Contest: Codeforces - Codeforces Global Round 8
// URL: https://codeforces.com/contest/1368/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    pi root = {1, 1};
    vector<pi> cells;
    cells.pb({0, 0});
    while (n >= 0)
    {
        cells.pb({root.first, root.second - 1});
        cells.pb({root.first - 1, root.second});
        cells.pb(root);
        root = {root.first + 1, root.second + 1};
        n--;
    }
    cout << cells.sz << endl;
    for (auto x : cells)
    {
        cout << x.first << wp << x.second << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
