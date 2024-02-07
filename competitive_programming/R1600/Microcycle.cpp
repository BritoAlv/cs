// Problem: F. Microcycle
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

int N, M, timer, compid;

vector<pair<int, int>> g[MAXN];
bool used[MAXN], isBridge[MAXM];
int comp[MAXN], tin[MAXN], minAncestor[MAXN];

vector<int> tree[MAXN]; // Store 2-edge-connected component tree.(Bridge tree).

void dfs(int v, int p)
{
    tin[v] = minAncestor[v] = ++timer;
    used[v] = 1;
    for (auto &e : g[v])
    {
        int to, id;
        tie(to, id) = e;
        if (to == p)
            continue;
        if (used[to])
        {
            minAncestor[v] = min(minAncestor[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            minAncestor[v] = min(minAncestor[v], minAncestor[to]);
            if (minAncestor[to] > tin[v])
            {
                isBridge[id] = true;
            }
        }
    }
}

void dfs1(int v, int p)
{
    used[v] = 1;
    comp[v] = compid;
    for (auto &e : g[v])
    {
        int to, id;
        tie(to, id) = e;

        if (isBridge[id])
        { // avoid traversing from this edge. so we get full component.
            continue;
        }
        if (used[to])
        {
            continue;
        }
        dfs1(to, v);
    }
}

vector<pair<int, int>> edges;

void addEdge(int from, int to, int id)
{
    g[from].push_back({to, id});
    g[to].push_back({from, id});
    edges[id] = {from, to};
}

void initB()
{

    for (int i = 0; i <= compid; ++i)
        tree[i].clear();
    for (int i = 1; i <= N; ++i)
        used[i] = false;
    for (int i = 1; i <= M; ++i)
        isBridge[i] = false;

    timer = 0;
    compid = 0;
}

void bridge_tree()
{

    initB();
    for (int i = 1; i <= N; i++)
    {
        if (!used[i])
        {
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= N; ++i)
        used[i] = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (!used[i])
        {
            dfs1(i, -1);
            ++compid;
        }
    }

    for (int i = 1; i <= M; ++i)
    {
        if (isBridge[i])
        {
            int u, v;
            tie(u, v) = edges[i];
            // connect two componets using edge.
            tree[comp[u]].push_back(comp[v]);
            tree[comp[v]].push_back(comp[u]);
        }
    }
}

void init()
{
    edges.clear();
    edges.resize(M + 1);
    for (int i = 1; i <= N; ++i)
        g[i].clear();
}

int visited[MAXN];
int p[MAXN];

void h_dfs(int a, vector<vector<int>> &graph)
{
    visited[a] = 1;
    for (auto z : graph[a])
    {
        if (!visited[z])
        {
            p[z] = a;
            h_dfs(z, graph);
        }
    }
}

void Solve()
{
    cin >> N >> M;

    init();
    vector<pair<int, pair<int, int>>> edges;
    vector<vector<int>> graph;
    for (int i = 0; i < N; i++)
    {
        graph.pb(vector<int>());
    }
    for (int i = 1; i <= M; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        addEdge(u, v, i);
        edges.pb({c, {u, v}});
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    bridge_tree();
    sort(edges.begin(), edges.end());
    for (auto x : edges)
    {
        int a = x.second.first;
        int b = x.second.second;
        if (comp[a] == comp[b])
        {
            a--;
            b--;
            for (int i = 0; i < N; i++)
            {
                visited[i] = 0;
                p[i] = -1;
            }
            vector<int> graph_a;
            vector<int> graph_b;
            for (auto z : graph[a])
            {
                if (z != b)
                {
                    graph_a.pb(z);
                }
            }
            for (auto z : graph[b])
            {
                if (z != a)
                {
                    graph_b.pb(z);
                }
            }
            graph[a] = graph_a;
            graph[b] = graph_b;
            h_dfs(a, graph);
            vector<int> path;
            path.pb(b);
            int actual = b;
            while (p[actual] != -1)
            {
                path.pb(p[actual]);
                actual = p[actual];
            }
            cout << x.first << wp << path.size() << endl;
            for (auto y : path)
            {
                cout << y + 1 << wp;
            }
            cout << endl;
            return;
        }
    }
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
