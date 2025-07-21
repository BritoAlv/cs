// Problem: F. 1-1-1, Free Tree!
// Contest: Codeforces - Codeforces Round 1037 (Div. 3)
// URL: https://codeforces.com/contest/2126/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags:
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

int n;
ll sum;
vector<map<int, ll>> sums_adj;
vector<ll> total_sum;
vi c;
vector<int> parent;
map<pi, int> edges_weight;

void change_color(int v, int new_c)
{
    sum -= (total_sum[v] - sums_adj[v][c[v]]);
    sum += (total_sum[v] - sums_adj[v][new_c]);

    if (v != 0)
    {
        int pr = parent[v];
        int we = edges_weight[{min(pr, v), max(pr, v)}];
        // parent v is considering v with some specific color.

        sum -= (total_sum[pr] - sums_adj[pr][c[pr]]);

        sums_adj[pr][c[v]] -= we;
        sums_adj[pr][new_c] += we;

        sum += (total_sum[pr] - sums_adj[pr][c[pr]]);
    }

    c[v] = new_c;
}

vector<int> top_sort;
vector<int> depth;

int bfs(int st, vector<vector<int>> &graph)
{
    int n = graph.size();
    top_sort.clear();
    parent = vector<int>(n, -1);
    depth = vector<int>(n, 1);
    queue<int> qq;
    qq.push(st);
    top_sort.pb(st);
    parent[st] = st;
    while (qq.size() > 0)
    {
        int t = qq.front();
        qq.pop();
        for (auto z : graph[t])
        {
            if (parent[z] == -1)
            {
                top_sort.pb(z);
                parent[z] = t;
                int we = edges_weight[{min(z, t), max(z, t)}];
                sums_adj[t][c[z]] += we;
                total_sum[t] += we;
                if (c[z] != c[t])
                    sum += we;
                qq.push(z);
            }
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    for (auto z : top_sort)
    {
        if (z != st)
            depth[parent[z]] += depth[z];
    }
    return 1;
}

void Solve()
{
    sum = 0;
    int q;
    cin >> n >> q;
    edges_weight.clear();
    sums_adj = vector<map<int, ll>>(n);
    vector<vi> adj2(n);
    c = vi(n, -1);
    total_sum = vl(n, 0);
    fori(0, n - 1)
    {
        cin >> c[i];
        c[i]--;
    }
    fori(0, n - 2)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj2[a].pb(b);
        adj2[b].pb(a);
        if (a > b)
            swap(a, b);
        edges_weight[{a, b}] = w;
    }
    bfs(0, adj2);
    while (q--)
    {
        int v, x;
        cin >> v >> x;
        v--;
        x--;
        change_color(v, x);
        cout << sum << endl;
    }
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}