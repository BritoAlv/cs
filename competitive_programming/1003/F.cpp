// Problem: F. Skibidus and Slay
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/problemset/problem/2065/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    vector<vi> adj(n, vi());
    vi can(n, 0);
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
        set<int> vals;
        vals.insert(a[i] - 1);
        for (auto v : adj[i])
        {
            int val = a[v] - 1;
            if (vals.count(val))
            {
                can[val] = 1;
            }
            vals.insert(val);
        }
    }
    fori(0, n - 1) cout << can[i];
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
