// Problem: C. Dora and Search
// Contest: Codeforces - Codeforces Round 852 (Div. 2)
// URL: https://codeforces.com/contest/1793/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

pi solve(int st, int ed, int minn, int maxx, vector<int> &a)
{
    if (st > ed || minn > a.sz || maxx < 1)
    {
        return {-1, -1};
    }
    if (a[st] == minn)
    {
        return solve(st + 1, ed, minn + 1, maxx, a);
    }
    if (a[st] == maxx)
    {
        return solve(st + 1, ed, minn, maxx - 1, a);
    }
    if (a[ed] == minn)
    {
        return solve(st, ed - 1, minn + 1, maxx, a);
    }
    if (a[ed] == maxx)
    {
        return solve(st, ed - 1, minn, maxx - 1, a);
    }
    return {st + 1, ed + 1};
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn
    {
        cin >> a[i];
    }
    auto p = solve(0, n - 1, 1, n, a);
    if (p.first != -1)
    {
        cout << p.first << wp << p.second << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
