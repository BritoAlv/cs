#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define inf 9223372036854775807

using namespace std;

map<pair<int, int>, long long> weights;
vector<vector<int>> graph;

void Solve()
{
    int n, m;
    cin >> n >> m;
    long long d[n];
    forn
    {
        d[i] = inf;
        graph.pb(vector<int>());
    }
    form
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--, b--;
        graph[a].pb(b);
        if (a != b)
        {
            if (weights.find({a, b}) == weights.end())
            {
                weights[{a, b}] = w;
            }
            else
            {
                weights[{a, b}] = min(w, weights[{a, b}]);
            }
        }
    }
    d[0] = 0;
    set<pair<long long, int>> PQ;
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
            if (d[z] > d[next.second] + weights[{next.second, z}])
            {
                PQ.erase({d[z], z});
                d[z] = d[next.second] + weights[{next.second, z}];
                PQ.insert({d[z], z});
            }
        }
    }
    forn
    {
        cout << d[i] << wp;
    }
    cout << endl;
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
