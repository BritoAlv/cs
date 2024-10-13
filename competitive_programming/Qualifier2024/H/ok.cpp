#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define ld long double
using namespace std;

const int INF = 1e9;
vector<int> distances(int s, vector<vector<int>> g)
{
    int n = g.size();
    vector<int> d = vector<int>(n, INF);
    d[s] = 0;
    set<pair<int, int>> PQ;
    forn
    {
        PQ.insert({d[i], i});
    }
    while (PQ.size() > 0)
    {
        auto next = *(PQ.begin());
        PQ.erase(next);
        for (auto z : g[next.second])
        {
            int q_w = 1;
            if (d[z] > d[next.second] + q_w)
            {
                PQ.erase({d[z], z});
                d[z] = d[next.second] + q_w;
                PQ.insert({d[z], z});
            }
        }
    }
    return d;
}

void solve()
{
    int n, g, k;
    cin >> n >> g >> k;
    g--;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vector<int> d = distances(g, graph);
    if (d[0] == INF)
    {
        cout << "NO ROUTE" << endl;
        return;
    }
    std::default_random_engine generator;
    std::mt19937 gen(generator());
    ld avg = 0;
    int iters = 100000000;
    for (int q = 0; q < iters; q++)
    {
        ld result = 0;
        int current = 0;
        while (current != g)
        {
            std::uniform_int_distribution<int> distribution(0, graph[current].size()-1);
            int next = graph[current][distribution(generator)];
            if (d[next] >= d[current])
            {
                result++;
            }
            current = next;
        }
        avg += result;
    }
    avg /= iters;
    avg = round(avg * 1000) / 1000;
    printf("%.3Lf", avg);
    cout << endl;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        solve();
    }
}