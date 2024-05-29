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

// 2^16 * 16*16 = 2^16 * 2^8 = 2^24 = 16777216 = 2*10^7

int hm_path(vector<vector<int>> &graph) // O(n^2 * 2^n)
{
    int n = graph.sz;
    int ans = 1;
    vector<vector<int>> dp(n, vector<int>(1 << n, 0)); // O(n * 2^n)
    for (int j = 0; j < n; j++)
    {
        dp[j][1 << j] = 1;
    }
    for (int subset = 1; subset < (1 << n); subset++) // O(2^n)
    {
        for (int vx = 0; vx < n; vx++) // O(n)
        {
            if (subset & (1 << vx))
            {
                for (auto x : graph[vx]) // O(n)
                {
                    if (subset & (1 << x))
                        dp[vx][subset] |= dp[x][subset - (1 << vx)];
                }
                if (dp[vx][subset])
                {
                    int ones = 0;
                    int cc = subset;
                    while (cc > 0)
                    {
                        ones += cc % 2;
                        cc /= 2;
                    }
                    ans = max(ans, ones);
                }
            }
        }
    }
    return ans;
}

void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> graph;
    vector<pair<string, string>> S(n);
    forn
    {
        cin >> S[i].first >> S[i].second;
        graph.pb(vector<int>());
    }
    forn
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i && (S[i].first == S[j].first || S[i].second == S[j].second))
            {
                graph[i].pb(j);
            }
        }
    }
    cout << n - hm_path(graph) << endl;
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