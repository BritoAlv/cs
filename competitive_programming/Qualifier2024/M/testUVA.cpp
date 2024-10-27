#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int cn = 1;

const ll INF = LONG_LONG_MAX;
// remember init n_v and adj vector.
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
    /*  cout << "Adding Edge from " << u << " to " << v << " with capacity " << cap << endl;
     */
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
    while (scanf("%d", &n) > 0 && n)
    {
        scanf("%d", &m);
        vector<int> duration(n);
        set<int> times;
        set<pair<pair<int, int>, int>> seg;
        forn
        {
            int st, ed;
            scanf("%d%d%d", &duration[i], &st, &ed);
            times.insert(st);
            times.insert(ed);
            seg.insert({{st, ed}, i});
        }
        vector<vector<int>> seg_active;
        vector<int> seg_active_times;
        vector<ll> capacity;
        int cs = *times.begin();
        times.erase(cs);
        while (times.size() > 0)
        {
            vector<int> active_tasks;
            int next = *times.begin();
            times.erase(next);
            for (auto &task : seg)
            {
                if (task.first.first <= cs && task.first.second > cs)
                {
                    active_tasks.pb(task.second);
                }
            }
            seg_active_times.pb(cs);
            seg_active.pb(active_tasks);
            capacity.push_back(next - cs);
            cs = next;
        }
        n_v = 1 + seg_active.size() * m + n * seg_active.size() + n + 1;
        adj = vector<vector<Edge>>(n_v);

        auto taskIndex = [&seg_active, &n, &m](int i) -> int {
            return 1 + seg_active.size() * m + n * seg_active.size() + i;
        };

        auto segtaskIndex = [&seg_active, &n, &m](int seg_i, int task_i) -> int {
            return 1 + seg_active.size() * m + seg_i * n + task_i;
        };

        auto seg_procIndex = [&seg_active, &n, &m](int seg_i, int proc_i) -> int { return 1 + seg_i * m + proc_i; };

        for (int i = 0; i < seg_active.size(); i++)
        {
            for (int pr = 0; pr < m; pr++)
            {
                int proc_index = seg_procIndex(i, pr);
                addEdge(0, proc_index, capacity[i]);
                for (auto t : seg_active[i])
                {
                    int segtask = segtaskIndex(i, t);
                    addEdge(proc_index, segtask, capacity[i]);
                }
            }
            for (int ti = 0; ti < n; ti++)
            {
                int segTask = segtaskIndex(i, ti);
                int taskInd = taskIndex(ti);
                addEdge(segTask, taskInd, capacity[i]);
            }
        }
        ll exp_flow = 0;
        forn
        {
            int ti = taskIndex(i);
            addEdge(ti, n_v - 1, duration[i]);
            exp_flow += duration[i];
        }
        int ans = flow(0, n_v - 1) == exp_flow;
        if (!ans)
        {
            printf("Case %d: No\n", cn++);
        }

        if (ans)
        {
            vector<vector<vector<pair<pair<int, int>, int>>>> P(seg_active.size(),
                                                                vector<vector<pair<pair<int, int>, int>>>(m));
            for (int seg_i = 0; seg_i < seg_active.size(); seg_i++)
            {
                int ct = seg_active_times[seg_i];
                int cp = 0;
                forn
                {
                    int v1 = segtaskIndex(seg_i, i);
                    if (adj[v1].size() == 0 || adj[v1].back().flow <= 0)
                        continue;
                    auto edge = adj[v1].back();
                    ll flow = abs(edge.flow);
                    if (flow > 0)
                    {
                        if (P[seg_i][cp].size() == 0)
                        {
                            P[seg_i][cp].push_back({{ct, ct + flow}, i});
                            if (P[seg_i][cp].back().first.second - ct == capacity[seg_i])
                            {
                                cp = (cp + 1) % m;
                            }
                        }
                        else
                        {
                            if (P[seg_i][cp].back().first.second - ct == capacity[seg_i])
                            {
                                cp = (cp + 1) % m;
                            }
                            ll minn = min(capacity[seg_i] - (P[seg_i][cp].back().first.second - ct), flow);
                            P[seg_i][cp].push_back(
                                {{P[seg_i][cp].back().first.second, P[seg_i][cp].back().first.second + minn}, i});
                            if (P[seg_i][cp].back().first.second - ct == capacity[seg_i])
                            {
                                cp = (cp + 1) % m;
                            }
                            ll rem = flow - minn;
                            if (rem > 0)
                            {
                                P[seg_i][cp].push_back({{ct, ct + rem}, i});
                            }
                        }
                    }
                }
            }
            vector<set<pair<pair<int, int>, int>>> D(n);
            vector<int> dur(n, 0);
            for (int seg_i = 0; seg_i < seg_active.size(); seg_i++)
            {
                for (int i = 0; i < m; i++)
                {
                    for (auto &z : P[seg_i][i])
                    {
                        D[z.second].insert({{z.first.first, z.first.second}, i});
                        dur[z.second] += z.first.second - z.first.first;
                    }
                }
            }
            printf("Case %d: Yes\n", cn++);
            forn
            {
                vector<pair<pair<int, int>, int>> pq;
                for (auto &z : D[i])
                {
                    if (pq.size() > 0 && pq.back().first.second == z.first.first)
                    {
                        pq.back().first.second += (z.first.second - z.first.first);
                    }
                    else
                    {
                        pq.push_back(z);
                    }
                }
                printf("%d", (int)pq.size());
                for (auto &z : pq)
                {
                    printf(" (%d,%d)", z.first.first, z.first.second);
                }
                puts("");
            }
        }
    }
}