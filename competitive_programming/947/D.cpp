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

int n;
vector<int> dist;
vector<int> vd;
vector<int> depth;
vector<int> ss_size;

void dfs(int v, vector<vector<int>> &graph)
{
    vd[v] = 1;
    int d = 0;
    ss_size[v] = 0;
    for (auto x : graph[v])
    {
        if (vd[x] == 0)
        {
            dfs(x, graph);
            d = max(d, 1 + depth[x]);
            ss_size[v] += (ss_size[x] + 1);
        }
    }
    depth[v] = d;
}

void bfs(int v, vector<vector<int>> &graph)
{
    vector<int> visited(n, 0);
    dist[v] = 0;
    visited[v] = 1;
    queue<int> q;
    q.push(v);
    while (q.sz > 0)
    {
        int next = q.front();
        q.pop();
        for (auto u : graph[next])
        {
            if (!visited[u])
            {
                dist[u] = dist[next] + 1;
                q.push(u);
                visited[u] = 1;
            }
        }
    }
}

int sh_travel(int x, vector<vector<int>> &graph)
{
    if (ss_size[x] == 0)
    {
        return 0;
    }
    int most_deep = -1;
    for (auto y : graph[x])
    {
        if (depth[y] < depth[x])
        {
            if (most_deep == -1 || depth[y] > depth[most_deep])
            {
                most_deep = y;
            }
        }
    }
    int ans = 0;
    for (auto y : graph[x])
    {
        if (depth[y] < depth[x])
        {
            if (y != most_deep)
            {
                ans += 2 * (ss_size[y] + 1);
            }
        }
    }
    return ans + 1 + sh_travel(most_deep, graph);
}

int option(int a, vector<vector<int>> &graph)
{
    dist = vector<int>(n);
    bfs(a, graph);
    depth = vector<int>(n);
    vd = vector<int>(n, 0);
    ss_size = vector<int>(n, 0);
    dfs(a, graph);
    return sh_travel(a, graph);
}

stack<int> pathAB(int A, int B, vector<vector<int>> &graph)
{
    int n = graph.sz;
    vector<int> visited(n, 0);
    vector<int> p(n, 0);
    queue<int> t;
    t.push(A);
    visited[A] = 1;
    p[A] = A;
    while (t.sz > 0)
    {
        auto next = t.front();
        t.pop();
        for (auto x : graph[next])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                p[x] = next;
                t.push(x);
            }
        }
    }
    stack<int> path;
    path.push(B);
    while (path.top() != A)
    {
        path.push(p[path.top()]);
    }
    return path;
}

void Solve()
{
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x - 1].pb(y - 1);
        graph[y - 1].pb(x - 1);
    }
    auto path = pathAB(a - 1, b - 1, graph);
    vector<int> p;
    while (path.sz > 0)
    {
        p.pb(path.top());
        path.pop();
    }
    int best = 0;
    if (path.sz % 2 == 1)
    {
        best = option(p[p.sz / 2], graph) + p.sz / 2;
    }
    else
    {
        best = option(p[(p.sz - 1) / 2], graph) + p.sz / 2;
    }
    cout << best << endl;
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