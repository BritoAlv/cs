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

vector<bool> visited;
vector<vector<int>> comp;
vector<vector<int>> adj_condensed;

void dfs(int v, vector<vector<int>> const &adj, vector<int> &output)
{
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

void strongly_connected_components(vector<vector<int>> const &adj, vector<vector<int>> &components,
                                   vector<vector<int>> &adj_cond)
{
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v])
        {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(begin(component), end(component));
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}

map<ll, set<ll>> groups_pos;
map<ll, set<ll>> groups_neg;
map<ll, int> pos_m;
ll k, n;

ll next_red(ll cur_time, ll pos, int dir)
{
    if (dir == 1)
    {
        ll group = (k + (cur_time % k) - (pos % k)) % k;
        auto pt = groups_pos[group].lower_bound(pos + 1);
        if (pt == groups_pos[group].end())
            return -1;
        else
            return *pt;
    }
    else
    {
        ll group = (k + (cur_time % k) + (pos % k)) % k;
        auto pt = groups_neg[group].lower_bound(pos);
        if (pt == groups_neg[group].begin())
            return -1;
        pt--;
        return *pt;
    }
}

void Solve()
{
    groups_pos = map<ll, set<ll>>();
    groups_neg = map<ll, set<ll>>();
    pos_m = map<ll, int>();
    cin >> n >> k;
    vl p(n);
    vl d(n);
    fori(0, n - 1) cin >> p[i];
    fori(0, n - 1) cin >> d[i];
    // left direction is +0, right direction is +n.
    vector<vi> adj(2 * n, vi());
    vi good(2 * n, 0);
    fori(0, n - 1)
    {
        pos_m[p[i]] = i;
        ll rem_pos = (k + (d[i] % k) - (p[i] % k)) % k;
        ll rem_neg = (k + (p[i] % k) + (d[i] % k)) % k;
        groups_pos[rem_pos].insert(p[i]);
        groups_neg[rem_neg].insert(p[i]);
    }
    fori(0, n - 1)
    {
        ll next1 = next_red(d[i] % k, p[i], 1); // I'm at this semaphore pointing right.
        ll next2 = next_red(d[i] % k, p[i], 0); // I'm at this semaphore pointing left.
        if (next1 != -1)
        {
            adj[i + n].pb(pos_m[next1]);
        }
        if (next2 != -1)
        {
            adj[i].pb(pos_m[next2] + n);
        }
    }
    strongly_connected_components(adj, comp, adj_condensed);
    for (auto scc : comp)
    {
        // cout << "SCC" << endl;
        for (auto v : scc)
        {
            // cout << v << endl;
            good[v] = scc.size() == 1;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        int dir = 1;
        if (pos_m.count(x) > 0)
        {
            int i = pos_m[x];
            if (d[i] % k == 0)
            {
                dir = 0;
            }
        }
        ll next = next_red(0, x, dir);
        // cout << x << wp << next << endl;
        int index = pos_m[next] + n * (!dir);
        if (next == -1 || good[index])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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