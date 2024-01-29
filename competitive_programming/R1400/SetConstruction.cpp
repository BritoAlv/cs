// Problem: C. Set Construction
// Contest: Codeforces - Pinely Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1761/C
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
using namespace std;

vector<int> t_sort;
int visited[100];

void dfs(int i, vector<vector<int>> graph)
{
    visited[i] = 1;
    for (auto x : graph[i])
    {
        if (!visited[x])
        {
            dfs(x, graph);
        }
    }
    t_sort.pb(i);
}

void Solve()
{
    int n;
    cin >> n;
    int m = n;
    vector<vector<int>> graph;
    t_sort = vector<int>();
    forn
    {
        graph.pb(vector<int>());
        form
        {
            char t;
            cin >> t;
            if (t == '1')
            {
                graph[i].pb(j);
            }
        }
    }
    forn
    {
        visited[i] = 0;
    }
    forn
    {
        if (!visited[i])
        {
            dfs(i, graph);
        }
    }
    reverse(t_sort.begin(), t_sort.end());
    vector<vector<int>> sets;
    forn
    {
        sets.pb(vector<int>());
    }
    forn
    {
        int to_fill = t_sort[i];
        sets[to_fill].pb(i + 1);
        for (auto x : graph[to_fill])
        {
            sets[x].pb(i + 1);
        }
    }
    forn
    {
        cout << sets[i].size() << wp;
        for (auto x : sets[i])
        {
            cout << x << wp;
        }
        cout << endl;
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
