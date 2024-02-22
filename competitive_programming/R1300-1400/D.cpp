// Problem: D. Divisible Pairs
// Contest: Codeforces - Codeforces Round 925 (Div. 3)
// URL: https://codeforces.com/contest/1931/problem/D
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

int x, y;

ull solve2(vector<int> values)
{
    int n = values.size();
    map<int, vector<int>> A;
    for (auto z : values)
    {
        if (A.find(z % x) == A.end())
        {
            A[z % x] = vector<int>();
        }
        A[z % x].pb(z);
    }
    ull ans = 0;
    for (auto rem : A)
    {
        int remm = rem.first;
        int to_find = (x - remm) % x;
        if (to_find != remm)
        {
            if (A.find(to_find) != A.end())
            {
                ans += rem.second.size() * A[to_find].size();
            }
        }
        else
        {
            ull t = rem.second.size();
            t *= (t - 1);
            ans += t;
        }
    }
    return ans / 2;
}

void Solve()
{
    int n;
    cin >> n >> x >> y;
    map<int, vector<int>> by_y;
    forn
    {
        int m;
        cin >> m;
        if (by_y.find(m % y) == by_y.end())
        {
            by_y[m % y] = vector<int>();
        }
        by_y[m % y].pb(m);
    }
    ull ans = 0;
    for (auto z : by_y)
    {
        ans += solve2(z.second);
    }
    cout << ans << endl;
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
