// Problem: E. Bertown roads
// Contest: Codeforces - Codeforces Beta Round 89 (Div. 2)
// URL: https://codeforces.com/contest/118/problem/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

vector<set<int>> graph;
vector<pair<int, int>> ans;
int levels[100000];
int dp[100000];
int bridge_c;

void dfs(int n)
{
    dp[n] = 0;
    for (auto x : graph[n])
    {
        if (levels[x] == -1)
        {
            levels[x] = levels[n] + 1;
            ans.pb({n + 1, x + 1});
            dfs(x);
            dp[n] += dp[x];
        }
        else
        {
            // I found a back edge but going up or down ?
            if (levels[x] < levels[n])
            {
                dp[n]++;
            }
            else if (levels[x] > levels[n])
            {
                dp[n]--;
            }
            ans.pb({n + 1, x + 1});
        }
    }
    dp[n]--;
    if (levels[n] > 0 && dp[n] == 0)
    {
        bridge_c++;
    }
}

void Solve()
{
    int numberv, numberedges;
    cin >> numberv >> numberedges;
    for (int i = 0; i < numberv; i++)
    {
        graph.pb(set<int>());
        levels[i] = -1;
    }
    for (int i = 0; i < numberedges; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    levels[0] = 0;
    bridge_c = 0;
    dfs(0);
    if (bridge_c > 0)
    {
        cout << 0 << endl;
    }
    else
    {
        map<int, set<int>> SS;
        for (int i = 0; i < numberv; i++)
        {
            SS[i] = set<int>();
        }
        for (auto x : ans)
        {
            if (SS[x.first].find(x.second) == SS[x.first].end() && SS[x.second].find(x.first) == SS[x.second].end())
            {
                cout << x.first << wp << x.second << endl;
                SS[x.first].insert(x.second);
                SS[x.second].insert(x.first);
            }
        }
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}