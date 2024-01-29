// Problem: B. Hossam and Friends
// Contest: Codeforces - Codeforces Round 837 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1771/B
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
    int n, m;
    cin >> n >> m;
    int minn[n + 1];
    for (int i = 1; i <= n + 1; i++)
    {
        minn[i] = n + 1;
    }
    int dp[n + 1];
    form
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            minn[b] = min(minn[b], a);
        }
        else
        {
            minn[a] = min(minn[a], b);
        }
    }
    dp[n] = n;
    for (int i = n - 1; i >= 1; i--)
    {
        dp[i] = min(minn[i] - 1, dp[i + 1]);
    }
    ull ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ull len = dp[i] - i + 1;
        ans += len;
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
