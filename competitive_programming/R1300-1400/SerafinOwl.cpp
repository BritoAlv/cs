// Problem: D. Seraphim the Owl
// Contest: Codeforces - Codeforces Round 935 (Div. 3)
// URL: https://codeforces.com/contest/1945/problem/D
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

void BruteSolve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(n);
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    vector<long long> prefix(n, 0);
    prefix[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + b[i];
    }
    vector<pair<long long, int>> dp(n + 1, {0, 0});
    for (int i = 0; i < m; i++)
    {
        dp[i] = {0, i};
    }
    for (int i = m; i < n + 1; i++)
    {
        dp[i] = {-1, -1};
        for (int j = i - 1; j >= 0; j--)
        {
            long long cost = a[j] + dp[j].first;
            cost += (prefix[i - 1] - prefix[j]);
            if (dp[i].first == -1 || cost < dp[i].first)
                dp[i] = {cost, j};
        }
    }
    cout << dp[n].first << endl;
    return;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(n);
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    vector<long long> prefix(n, 0);
    prefix[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + b[i];
    }
    vector<pair<long long, int>> dp(n + 1, {0, 0});
    for (int i = 0; i < m; i++)
    {
        dp[i] = {0, i};
    }
    for (int i = m; i <= m; i++)
    {
        dp[i] = {-1, -1};
        for (int j = i - 1; j >= 0; j--)
        {
            long long cost = a[j] + dp[j].first;
            cost += (prefix[i - 1] - prefix[j]);
            if (dp[i].first == -1 || cost < dp[i].first)
                dp[i] = {cost, j};
        }
    }
    for (int i = m + 1; i < n + 1; i++)
    {
        dp[i] = {-1, -1};
        vector<int> candidates;
        candidates.pb(i - 1);
        candidates.pb(dp[i - 1].second);
        for (auto j : candidates)
        {
            long long cost = a[j] + dp[j].first;
            cost += (prefix[i - 1] - prefix[j]);
            if (dp[i].first == -1 || cost < dp[i].first)
                dp[i] = {cost, j};
        }
    }
    cout << dp[n].first << endl;
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
