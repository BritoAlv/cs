// Problem: E. Reachability from the Capital
// Contest: Codeforces - Codeforces Round 490 (Div. 3)
// URL: https://codeforces.com/contest/999/problem/E
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

int n;
int m;
int s;
vector<vector<int>> graph_o;
vector<vector<int>> graph_r;
vector<int> top_sort;

int reach_a[5000];
int visited[5000];

void dfs1(int x)
{
    if (visited[x])
    {
        return;
    }
    visited[x] = 1;
    for (auto y : graph_o[x])
    {
        if (!reach_a[y])
        {
            dfs1(y);
        }
    }
    top_sort.pb(x);
}

void dfs2(int x, int label)
{
    if (visited[x])
    {
        return;
    }
    visited[x] = label;
    for (auto y : graph_r[x])
    {
        if (!reach_a[y])
        {
            dfs2(y, label);
        }
    }
}

void bfs()
{
    forn
    {
        reach_a[i] = 0;
    }
    reach_a[s - 1] = 1;
    queue<int> q;
    q.push(s - 1);
    while (q.size() > 0)
    {
        auto next = q.front();
        q.pop();
        for (auto x : graph_o[next])
        {
            if (!reach_a[x])
            {
                reach_a[x] = 1;
                q.push(x);
            }
        }
    }
}

void Solve()
{
    cin >> n >> m >> s;
    forn
    {
        graph_o.pb(vector<int>());
        graph_r.pb(vector<int>());
    }
    form
    {
        int a, b;
        cin >> a >> b;
        graph_o[a - 1].pb(b - 1);
        graph_r[b - 1].pb(a - 1);
    }
    bfs();
    forn
    {
        if (!reach_a[i])
        {
            dfs1(i);
        }
    }
    forn
    {
        visited[i] = 0;
    }
    reverse(top_sort.begin(), top_sort.end());
    int number = 1;
    for (int i = 0; i < top_sort.size(); i++)
    {
        if (!visited[top_sort[i]])
        {
            dfs2(top_sort[i], number);
            number++;
        }
    }
    number--;
    vector<vector<int>> new_graph;
    for (int i = 0; i < number; i++)
    {
        new_graph.pb(vector<int>());
    }
    forn
    {
        for (auto x : graph_o[i])
        {
            if (!reach_a[x] && !reach_a[i])
            {
                if (visited[i] != visited[x])
                {
                    new_graph[visited[x] - 1].pb(visited[i] - 1);
                }
            }
        }
    }
    int ans = 0;
    for (auto x : new_graph)
    {
        if (x.size() == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
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
