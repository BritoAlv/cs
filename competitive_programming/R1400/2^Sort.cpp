// Problem: G. 2^Sort
// Contest: Codeforces - Codeforces Round 799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/G
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
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    int dp[n];
    forn
    {
        dp[i] = 0;
        cin >> a[i];
        if (i >= 1 && a[i - 1] < 2 * a[i])
        {
            dp[i] = 1;
        }
    }
    forn
    {
        if (i > 0 && dp[i])
        {
            dp[i] += dp[i - 1];
        }
    }
    int ans = 0;
    for (int i = k; i < n; i++)
    {
        if (dp[i] >= k)
        {
            ans++;
        }
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
