// Problem: B. Puzzles
// Contest: Codeforces - Codeforces Round 362 (Div. 1)
// URL: https://codeforces.com/contest/696/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define even(x) ((x) % 2 == 0)
#define odd(x) ((x) % 2 == 1)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
#define print(x, name)                                                                                                 \
    cout << name << endl;                                                                                              \
    for (auto z : x)                                                                                                   \
        cout << z << wp;                                                                                               \
    cout << endl;
// je m appelle Alvaro j ai 21 ans.
int test_cases;
int test_cases_original;
#define t_number test_cases_original - test_cases

using namespace std;

void dfs(int st, vector<vi> &graph, vi &depth)
{
    for (auto x : graph[st])
    {
        dfs(x, graph, depth);
        depth[st] += (depth[x] + 1);
    }
}

void dfs2(int pr, vector<vi> &graph, vi &depth, vector<double> &sta)
{
    int cn = sz(graph[pr]);
    for (auto x : graph[pr])
    {
        sta[x] = sta[pr] + 1;
    }
    if (cn >= 2)
    {
        double len = 0.5;
        double de = depth[pr];
        for (auto x : graph[pr])
        {
            sta[x] += (de - depth[x] - 1) * len;
        }
    }
    for (auto x : graph[pr])
    {
        dfs2(x, graph, depth, sta);
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<vi> graph(n, vi());
    vector<double> sta(n, 0);
    sta[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        graph[x - 1].pb(i);
    }
    vi depth(n, 0);
    dfs(0, graph, depth);
    dfs2(0, graph, depth, sta);
    forn
    {
        printf("%.9f ", sta[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
