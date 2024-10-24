const int INF = 1E9 + 5;

struct Edge
{
    int v;
    int cap, flow;
    int rid;
};

int n_v;
vector<vector<Edge>> adj;
vector<int> dist, ptr;
void addEdge(int u, int v, int cap)
{
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

int dfs(int u, int t, int flow)
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

int flow(int s, int t)
{
    ptr = vector<int>(n_v, 0);
    dist = vector<int>(n_v, 0);
    int res = 0;
    while (bfs(s, t))
    {
        for (int i = 0; i < n_v; i++)
        {
            ptr[i] = 0;
        }
        int cflow = dfs(s, t, INF);
        while (cflow > 0)
        {
            res += cflow;
            cflow = dfs(s, t, INF);
        }
    }
    return res;
}
