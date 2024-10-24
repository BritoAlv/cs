#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int A, B;

vector<vector<int>> resolver(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> chosen;
    map<int, int> reversed;
    int pt = 0;
    forn
    {
        int sz = graph[i].size();
        if (sz >= A && sz <= n - 1 - B)
        {
            chosen.pb(i);
            reversed[i] = pt++;
        }
    }
    vector<vector<int>> result(chosen.size(), vector<int>());
    for(auto i : chosen)
    {
        for(auto v : graph[i])
        {
            if(reversed.find(v) != reversed.end())
            {
                result[reversed[i]].pb(reversed[v]);
            }
        }
    }
    return result;
}

int valid(vector<vector<int>> &graph)
{
    int n = graph.size();
    for (auto &z : graph)
    {
        int sz = z.size();
        if (sz < A || sz > n - 1 - B)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m >> A >> B;
    vector<vector<int>> G(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[--a].pb(--b);
        G[b].pb(a);
    }
    while (G.size() > 0 && !valid(G))
    {
        G = resolver(G);
    }
    cout << G.size() << endl;
}