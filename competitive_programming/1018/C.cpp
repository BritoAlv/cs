// Problem: C. Wonderful City
// Contest: Codeforces - Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/2096/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags: invariant observation, dp
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

ll INF = 1e18;

ll solve(vl &a, vector<vl> rows)
{
    set<int> less;
    set<int> great;
    set<int> equal;
    int n = a.size();
    fori(0, n - 1)
    {
        forj(1, n - 1)
        {
            if (rows[i][j] + 1 == rows[i][j - 1])
                less.insert(j);
            if (rows[i][j] - 1 == rows[i][j - 1])
                great.insert(j);
            if (rows[i][j] == rows[i][j - 1])
                equal.insert(j);
        }
    }
    vector<vector<ll>> dp(n, vl(2));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    fori(1, n - 1)
    {
        if (great.count(i) > 0 && less.count(i) > 0 && equal.count(i) > 0)
        {
            return INF;
        }
        else if (great.count(i) > 0 && less.count(i) > 0)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + a[i];
        }
        else if (great.count(i) > 0 && equal.count(i) > 0)
        {
            dp[i][0] = INF;
            dp[i][1] = dp[i - 1][0] + a[i];
        }
        else if (less.count(i) > 0 && equal.count(i) > 0)
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = INF;
        }
        else if (great.count(i) > 0)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = a[i] + min(dp[i - 1][0], dp[i - 1][1]);
        }
        else if (less.count(i) > 0)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = a[i] + dp[i - 1][1];
        }
        else if (equal.count(i) > 0)
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = a[i] + dp[i - 1][0];
        }
        else
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = a[i] + min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    if (dp[n - 1][0] >= INF && dp[n - 1][1] >= INF)
    {
        return INF;
    }
    else if (dp[n - 1][0] >= INF)
    {
        return dp[n - 1][1];
    }
    else if (dp[n - 1][1] >= INF)
    {
        return dp[n - 1][0];
    }
    else
    {
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> board1(n, vector<ll>(n));
    vector<vector<ll>> board2(n, vector<ll>(n));
    fori(0, n - 1)
    {
        forj(0, n - 1)
        {
            ll x;
            cin >> x;
            board1[i][j] = x;
            board2[j][i] = x;
        }
    }
    vl a(n), b(n);
    fori(0, n - 1) cin >> a[i];
    fori(0, n - 1) cin >> b[i];
    ll one = solve(b, board1);
    ll two = solve(a, board2);
    if (one == INF || two == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << one + two << endl;
    }
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
