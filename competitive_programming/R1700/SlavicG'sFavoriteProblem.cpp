// Problem: G. SlavicG's Favorite Problem
// Contest: Codeforces - Codeforces Round 835 (Div. 4)
// URL: https://codeforces.com/contest/1760/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

void Solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<int>> graph;
    int db[n];
    int da[n];
    map<pair<int, int>, int> weights;
    forn
    {
        graph.pb(vector<int>());
        db[i] = -1;
        da[i] = -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].pb(v);
        graph[v].pb(u);
        weights[{min(u, v), max(u, v)}] = w;
    }
    db[b] = 0;
    queue<int> q1;
    q1.push(b);
    while (q1.size() > 0)
    {
        int top = q1.front();
        q1.pop();
        for (auto x : graph[top])
        {
            if (db[x] == -1)
            {
                db[x] = db[top] ^ weights[{min(x, top), max(x, top)}];
                q1.push(x);
            }
        }
    }
    da[a] = 0;
    q1.push(a);
    while (q1.size() > 0)
    {
        int top = q1.front();
        q1.pop();
        for (auto x : graph[top])
        {
            if (da[x] == -1 && x != b)
            {
                da[x] = da[top] ^ weights[{min(x, top), max(x, top)}];
                q1.push(x);
            }
        }
    }
    set<int> Bs;
    if (da[b] == 0)
    {
        cout << "YES" << endl;
        return;
    }
    forn
    {
        Bs.insert(db[i]);
    }
    int count = 0;
    forn
    {
        if (db[i] == db[b])
        {
            count++;
        }
    }
    forn
    {
        if (i == b)
        {
            if (da[i] == 0)
            {
                cout << "YES" << endl;
                return;
            }
        }
        else
        {
            if (Bs.find(da[i]) != Bs.end())
            {
                if (da[i] == db[b])
                {
                    if (count > 1)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
                else
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
