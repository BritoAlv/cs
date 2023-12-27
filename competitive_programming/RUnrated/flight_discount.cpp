#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define inf 9223372036854775807

using namespace std;

struct Edge
{
    int to, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

unsigned long long d_d_graph[100000];
unsigned long long d_r_graph[100000];

set<pair<long long, int>> PQ;

void Dijstra(int n, int source, unsigned long long d[], vector<vector<Edge>> &graph)
{
    forn
    {
        d[i] = inf;
    }
    d[source] = 0;
    forn
    {
        PQ.insert({d[i], i});
    }
    while (PQ.size() > 0)
    {
        auto next = *(PQ.begin());
        PQ.erase(next);
        for (auto z : graph[next.second])
        {
            if (d[z.to] > d[next.second] + z.weight)
            {
                PQ.erase({d[z.to], z.to});
                d[z.to] = d[next.second] + z.weight;
                PQ.insert({d[z.to], z.to});
            }
        }
    }
    return;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> d_graph;
    vector<vector<Edge>> r_graph;
    forn
    {
        d_graph.pb(vector<Edge>());
        r_graph.pb(vector<Edge>());
    }
    form
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        d_graph[a].pb({b, w});
        r_graph[b].pb({a, w});
    }
    Dijstra(n, 0, d_d_graph, d_graph);
    Dijstra(n, n - 1, d_r_graph, r_graph);
    unsigned long long ans = inf;
    for (int i = 0; i < n; i++)
    {
        for (auto x : d_graph[i])
        {
            int s = i;
            int end = x.to;
            if (d_d_graph[s] != inf && d_r_graph[end] != inf)
            {
                ans = min(ans, d_d_graph[s] + d_r_graph[end] + x.weight / 2);
            }
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
