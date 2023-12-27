// Problem: E. One-Way Reform
// Contest: Codeforces - Codeforces Round 375 (Div. 2)
// URL: https://codeforces.com/contest/723/problem/E
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

using namespace std;

int p[200000];

void dfs(int n, vector<vector<int>> &graph, vector<int> &tps)
{
    for (auto x : graph[n])
    {
        if (p[x] == -1)
        {
            p[x] = n;
            dfs(x, graph, tps);
        }
    }
    tps.pb(n);
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    forn
    {
        p[i] = -1;
        graph.pb(vector<int>());
    }
    vector<pair<int, int>> normal_edges;
    vector<pair<int, int>> special_edges;
    form
    {
        int u, a, b;
        cin >> u >> a >> b;
        a--, b--;
        if (u == 1)
        {
            graph[a].pb(b);
            normal_edges.pb({a, b});
        }
        else
        {
            special_edges.pb({a, b});
        }
    }
    vector<int> tps;
    forn
    {
        if (p[i] == -1)
        {
            p[i] = i;
            dfs(i, graph, tps);
        }
    }
    reverse(tps.begin(), tps.end());
    map<int, int> pos;
    forn
    {
        pos[tps[i]] = i;
    }
    forn
    {
        int poss = i;
        int index = tps[i];
        for (auto x : graph[index])
        {
            if (pos[x] < poss)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto x : special_edges)
    {
        int b = pos[x.first];
        int c = pos[x.second];
        if (b < c)
        {
            cout << x.first + 1 << wp << x.second + 1 << endl;
        }
        else
        {
            cout << x.second + 1 << wp << x.first + 1 << endl;
        }
    }
    for (auto y : normal_edges)
    {
        cout << y.first + 1 << wp << y.second + 1 << endl;
    }

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
