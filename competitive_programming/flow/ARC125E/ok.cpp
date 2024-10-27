#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

const ll INF = LONG_LONG_MAX;

struct Edge
{
    int v;
    ll cap, flow;
    int rid;
};

int n_v;
vector<vector<Edge>> adj;
vector<int> dist, ptr;
void addEdge(int u, int v, ll cap)
{
    //cout << "Adding Edge from " << u << " to " << v << " with apacity " << cap << endl;
    int id = adj[u].size(), rid = adj[v].size();
    adj[u].pb({v, cap, 0, rid});
    adj[v].pb({u, 0, 0, id});
}

bool bfs(int s, int t)
{
    for (int i = 0; i < n_v; i++)
    {
        dist[i] = -1;
    }
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (Edge &e : adj[u])
        {
            if (e.cap == e.flow)
            {
                continue;
            }
            if (dist[e.v] != -1)
            {
                continue;
            }
            dist[e.v] = dist[u] + 1;
            q.push(e.v);
        }
    }
    return dist[t] != -1;
}

int dfs(int u, int t, ll flow)
{
    if (u == t)
        return flow;
    for (; ptr[u] < adj[u].size(); ptr[u]++)
    {
        Edge &e = adj[u][ptr[u]];
        if (dist[u] + 1 != dist[e.v])
            continue;
        if (e.cap == e.flow)
            continue;
        int cflow = min(flow, e.cap - e.flow);
        cflow = dfs(e.v, t, cflow);
        if (cflow > 0)
        {
            e.flow += cflow;
            adj[e.v][e.rid].flow -= cflow;
            return cflow;
        }
    }
    return 0;
}

ll flow(int s, int t)
{
    ptr = vector<int>(n_v, 0);
    dist = vector<int>(n_v, 0);
    ll res = 0;
    while (bfs(s, t))
    {
        for (int i = 0; i < n_v; i++)
        {
            ptr[i] = 0;
        }
        ll cflow = dfs(s, t, INF);
        while (cflow > 0)
        {
            res += cflow;
            cflow = dfs(s, t, INF);
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    n_v = n + m + 2;
    adj = vector<vector<Edge>>(n_v);
    vector<ll> a(n);
    vector<ll> b(m);
    vector<ll> c(m);
    forn
    {
        cin >> a[i];
        addEdge(0, i + 1, a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        for (int j = 1; j <= n; j++)
        {
            addEdge(j, n + 1 + i, b[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
        addEdge(n + 1 + i, n + m + 1, c[i]);
    }
    cout << flow(0, n + m + 1) << endl;
}