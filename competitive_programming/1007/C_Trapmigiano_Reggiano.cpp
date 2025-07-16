// Problem: C. Trapmigiano Reggiano
// Contest: Codeforces - Codeforces Round 1007 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2071/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags: bfs depth is decreasing, invariant, math observation.
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

vector<vi> adj;

void bfs_prefered(int st, int excluded1, int excluded2)
{
    int n = adj.size();
    queue<int> d;
    vi bfs_order;
    map<int, int> P;
    P[st] = st;
    d.push(st);
    bfs_order.pb(st);
    while (d.size())
    {
        int next = d.front();
        d.pop();
        for (auto z : adj[next])
        {
            if (P.count(z) == 0 && z != excluded1 && z != excluded2)
            {
                d.push(z);
                bfs_order.pb(z);
                P[z] = next;
            }
        }
    }
    reverse(bfs_order.begin(), bfs_order.end());
    for (auto z : bfs_order)
    {
        cout << z + 1 << wp;
    }
}

vi bfs_path(int st, int ed)
{
    queue<int> d;
    int n = adj.size();
    vi p(n, -1);
    p[st] = st;
    d.push(st);
    while (d.size())
    {
        int next = d.front();
        d.pop();
        for (auto z : adj[next])
        {
            if (p[z] == -1)
            {
                p[z] = next;
                d.push(z);
            }
        }
    }
    vi path;
    path.pb(ed);
    while (path.back() != st)
    {
        path.pb(p[ed]);
        ed = p[ed];
    }
    reverse(path.begin(), path.end());
    return path;
}

void Solve()
{
    int n, st, ed;
    cin >> n >> st >> ed;
    st--, ed--;
    adj = vector<vi>(n, vi());
    fori(0, n - 2)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi path = bfs_path(st, ed); // vector starting in st, ending at ed if st != ed.
    if (path.size() == 1)
    {
        bfs_prefered(path[0], -1, -1);
    }
    else
    {
        n = path.size();
        fori(0, n - 2)
        {
            // print that vertex bfs taking that vertex as root,
            // not going to that adittional branch.
            bfs_prefered(path[i], path[i + 1], (i > 0 ? path[i - 1] : path[i + 1]));
        }
        bfs_prefered(path[n - 1], path[n - 2], path[n - 2]);
    }
    cout << endl;
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