#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

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

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> P(n);
    forn
    {
        cin >> P[i].first >> P[i].second;
    }
    int ans = 0;
    n_v = 1 + n + n + 1;
    forn
    {
        // O(n)
        adj = vector<vector<Edge>>(n_v);
        int w = i + 1;
        set<int> second_group;
        for (int j = 0; j < n; j++)
        {
            if (P[j].first != w && P[j].second != w && i != j)
            {
                second_group.insert(j);
            }
        }
        int wolf_k = n - 1 - second_group.size();
        if (wolf_k == 0)
        {
            ans++;
            //cout << i << wp;
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (second_group.find(j) == second_group.end() && j != i)
            {
                addEdge(0, j + 1, 0);
                int p1 = P[j].first;
                int p2 = P[j].second;
                addEdge(j + 1, p1 + n, 0);
                addEdge(j + 1, p2 + n, 0);
            }
            else if (j == i)
            {
                addEdge(0, j + 1, 0);
                int p1 = P[j].first;
                int p2 = P[j].second;
                addEdge(j + 1, p1 + n, 0);
                addEdge(j + 1, p2 + n, 0);
            }
            else if (second_group.find(j) != second_group.end())
            {
                addEdge(0, j + 1, 1);
                int p1 = P[j].first;
                int p2 = P[j].second;
                addEdge(j + 1, p1 + n, 1);
                addEdge(j + 1, p2 + n, 1);
            }
            if (j + 1 == P[i].first || j + 1 == P[i].second)
            {
                addEdge(j + 1 + n, n_v - 1, max(wolf_k - 2, 0));
            }
            else
            {
                addEdge(j + 1 + n, n_v - 1, wolf_k - 1);
            }
        }
        // build the graph is linear so at this point looks cuadratic.
        int f = flow(0, n_v - 1);
        if (f < second_group.size())
        {
            // not everyone could vote without violating restriction so wolf wins.
            ans++;
            //cout << i << wp;
        }
    }
    cout << ans << endl;
    //cout << endl;
}