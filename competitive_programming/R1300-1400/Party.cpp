// Problem: B. Party
// Contest: Codeforces - Codeforces Round 810 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1711/B
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
    long long a[n];
    long long best_ans = 0;
    vector<vector<int>> graph;
    forn
    {
        cin >> a[i];
        best_ans += a[i];
        graph.pb(vector<int>());
    }
    vector<pair<int, int>> edges;
    form
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
        edges.pb({a - 1, b - 1});
    }
    if (m % 2 == 0)
    {
        best_ans = 0;
    }
    else
    {
        forn
        {
            if ((m - graph[i].size()) % 2 == 0)
            {
                best_ans = min(best_ans, a[i]);
            }
        }
        for (auto x : edges)
        {
            if ((m - (graph[x.first].size() + graph[x.second].size() - 1)) % 2 == 0)
            {
                best_ans = min(best_ans, a[x.first] + a[x.second]);
            }
        }
        // edges without 1 and 2.
    }
    cout << best_ans << endl;
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
