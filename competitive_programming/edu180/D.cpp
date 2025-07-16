// You might break and that's okay.
// Tags:
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
vi visited;
int n;

void dfs(int root, int state)
{
    visited[root] = 1;
    for (auto z : adj[root])
    {
        if (!visited[z])
        {
            if (state)
            {
                cout << root + 1 << wp << z + 1 << endl;
            }
            else
            {
                cout << z + 1 << wp << root + 1 << endl;
            }
            dfs(z, !state);
        }
    }
}

void Solve()
{
    cin >> n;
    adj = vector<vi>(n, vi());
    visited = vi(n, 0);
    fori(0, n - 2)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    fori(0, n - 1)
    {
        if (adj[i].size() == 2)
        {
            cout << "YES" << endl;
            cout << (i + 1) << wp << adj[i][0] + 1 << endl;
            cout << adj[i][1] + 1 << wp << (i + 1) << endl;
            visited[i] = 1;
            dfs(adj[i][0], 0);
            dfs(adj[i][1], 1);
            return;
        }
    }
    cout << "NO" << endl;
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