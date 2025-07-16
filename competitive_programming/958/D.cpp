// Problem: D. The Omnipotent Monster Killer
// Contest: Codeforces - Codeforces Round 958 (Div. 2)
// URL: https://codeforces.com/contest/1988/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
    fori(0, n - 2)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int number_colors = min(n, 40);
    vector<vl> dp(n, vl(number_colors));
    vector<vl> dp2(n, vl(number_colors));

    vi visited(n, 0);
    vi parent(n, -1);

    queue<int> q;
    stack<int> qq;
    q.push(0);
    qq.push(0);
    visited[0] = 1;
    parent[0] = 0;
    while (q.size())
    {
        int next = q.front();
        q.pop();
        for (auto v : adj[next])
        {
            if (!visited[v])
            {
                q.push(v);
                qq.push(v);
                visited[v] = 1;
                parent[v] = next;
            }
        }
    }
    while (qq.size())
    {
        int next = qq.top();
        qq.pop();
        for (ll i = 0; i < number_colors; i++)
        {
            dp[next][i] = (i + 1) * a[next];
            // this way is quadratic in the number of colors.
            // what I need is sum of the minimums taken except using one color.
            for (auto z : adj[next])
            {
                if (z != parent[next])
                {
                    dp[next][i] += dp2[z][i];
                }
            }
        }
        vector<ll> mins_prefix(number_colors);
        vector<ll> mins_suffix(number_colors);
        fori(0, number_colors - 1)
        {
            mins_prefix[i] = dp[next][i];
            if (i > 0)
                mins_prefix[i] = min(mins_prefix[i], mins_prefix[i - 1]);
        }
        for (int i = number_colors - 1; i >= 0; i--)
        {
            mins_suffix[i] = dp[next][i];
            if (i < number_colors - 1)
                mins_suffix[i] = min(mins_suffix[i], mins_suffix[i + 1]);
        }
        fori(0, number_colors - 2)
        {
            dp2[next][i] = mins_suffix[i + 1];
        }
        fori(1, number_colors - 1)
        {
            if (i == number_colors - 1)
            {
                dp2[next][i] = mins_prefix[i - 1];
            }
            else
            {
                dp2[next][i] = min(dp2[next][i], mins_prefix[i - 1]);
            }
        }
    }
    ll ans = dp[0][0];
    fori(1, number_colors - 1) ans = min(ans, dp[0][i]);
    cout << ans << endl;
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
