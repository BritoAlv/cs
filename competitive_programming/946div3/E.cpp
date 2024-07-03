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
    int n, x;
    cin >> n >> x;
    vector<pi> c(n);
    long long sum = 0;
    forn
    {
        cin >> c[i].first >> c[i].second;
        sum += c[i].second;
    }
    int m = sum + 1;
    vector<vector<long long>> dp(n + 1, vector<long long>(m, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        form
        {
            if (dp[i][j] != -1)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
                if (dp[i][j] >= c[i].first)
                {
                    dp[i + 1][min(m - 1, j + c[i].second)] =
                        max(dp[i + 1][min(m - 1, j + c[i].second)], dp[i][j] - c[i].first + x);
                }
            }
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (dp[n][i] >= 0)
        {
            cout << i << endl;
            return;
        }
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