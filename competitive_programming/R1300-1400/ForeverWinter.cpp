// Problem: F. Forever Winter
// Contest: Codeforces - Codeforces Round 871 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1829/F
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

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    forn
    {
        graph.pb(vector<int>());
    }
    form
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int product = 0;
    forn
    {
        if (graph[i].size() == 1)
        {
            product++;
        }
    }
    int x = m - product;
    cout << x << wp << product / x << endl;
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
