// Problem: C. Zero Path
// Contest: Codeforces - Codeforces Round 801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));
    vector<vector<pair<int, int>>> dp;
    forn
    {
        dp.push_back(vector<pair<int, int>>(m));
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
            table[i][j] = max(0, table[i][j]);
        }
    }

    dp[0][0] = make_pair(table[0][0], table[0][0]);

    for (int i = 1; i < m; i++)
    {
        dp[0][i] = make_pair(dp[0][i - 1].first + table[0][i], dp[0][i - 1].second + table[0][i]);
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = make_pair(dp[i - 1][0].first + table[i][0], dp[i - 1][0].second + table[i][0]);
    }

    int start = 1;
    while (start < min(n, m))
    {
        for (int i = start; i < m; i++)
        {
            dp[start][i] = make_pair(min(dp[start - 1][i].first, dp[start][i - 1].first) + table[start][i],
                                     max(dp[start - 1][i].second, dp[start][i - 1].second) + table[start][i]);
        }
        for (int i = start + 1; i < n; i++)
        {
            dp[i][start] = make_pair(min(dp[i][start - 1].first, dp[i - 1][start].first) + table[i][start],
                                     max(dp[i][start - 1].second, dp[i - 1][start].second) + table[i][start]);
        }
        start++;
    }
    if (dp[n - 1][m - 1].first <= (n + m - 1) / 2 && dp[n - 1][m - 1].second >= (n + m - 1) / 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
