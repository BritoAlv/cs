// Problem: C. Tree Cutting
// Contest: Codeforces - Codeforces Round 936 (Div. 2)
// URL: https://codeforces.com/contest/1946/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

int w(int x, int k, vector<vector<int>> &graph)
{
    vector<int> levels;
    int n = graph.sz;
    vector<int> parent(n, -1);
    vector<int> depth(n, 1);
    queue<int> qq;
    qq.push(0);
    levels.pb(0);
    parent[0] = 0;
    while (qq.sz > 0)
    {
        int t = qq.front();
        qq.pop();
        for (auto z : graph[t])
        {
            if (parent[z] == -1)
            {
                levels.pb(z);
                parent[z] = t;
                qq.push(z);
            }
        }
    }
    reverse(levels.begin(), levels.end());
    int count = k + 1;
    for (auto z : levels)
    {
        if (z != 0)
            depth[parent[z]] += depth[z];
        if (depth[z] >= x)
        {
            count--;
            depth[parent[z]] -= depth[z];
        }
    }
    return count <= 0;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph;
    forn
    {
        graph.pb(vector<int>());
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[--a].pb(--b);
        graph[b].pb(a);
    }
    int lw = 1;
    int up = n - 1;
    while (up - lw > 1)
    {
        int md = lw + (up - lw) / 2;
        if (w(md, k, graph))
        {
            lw = md;
        }
        else
        {
            up = md - 1;
        }
    }
    if (w(lw + 1, k, graph))
    {
        cout << lw + 1 << endl;
    }
    else
    {
        cout << lw << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
