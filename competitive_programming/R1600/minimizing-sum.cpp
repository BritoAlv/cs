// Problem: C. Minimizing the Sum
// Contest: Codeforces - Educational Codeforces Round 165 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1969/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    forn
    {
        cin >> arr[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(k + 1));
    dp[0][0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = arr[i] + dp[i - 1][0];
    }
    forn
    {
        for (int kk = 1; kk <= k; kk++)
        {
            vector<long long> candidates;
            for (int op = 0; op <= kk; op++)
            {
                long long minn = arr[i];
                for (int j = i; j >= i - op && j >= 0; j--)
                {
                    minn = min(minn, arr[j]);
                }
                if (op >= i)
                {
                    candidates.pb((i + 1) * minn);
                }
                else
                {
                    candidates.pb(dp[i - op - 1][kk - op] + (op + 1) * minn);
                }
            }
            sort(candidates.begin(), candidates.end());
            dp[i][kk] = candidates[0];
        }
    }
    cout << dp[n - 1][k] << endl;
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
