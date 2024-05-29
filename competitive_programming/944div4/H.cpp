// Problem: H. ±1
// Contest: Codeforces - Codeforces Round 944 (Div. 4)
// URL: https://codeforces.com/contest/1971/problem/H
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

int n;
vector<vector<int>> adj, adj_x;
vector<bool> used;
vector<int> order, comp;
vector<int> assignment;

void dfs1(int v)
{
    used[v] = true;
    for (int u : adj[v])
    {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl)
{
    comp[v] = cl;
    for (int u : adj_x[v])
    {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT()
{
    order.clear();
    used.clear();
    comp.clear();
    used.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i)
    {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, 0);
    for (int i = 0; i < n; i += 2)
    {
        if (comp[i] == comp[i + 1])
            return 0;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return 1;
}

void add_disjunction(int a, bool na, int b, bool nb)
{
    // na and nb signify whether a and b are to be negated
    a = 2 * a ^ na;
    b = 2 * b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_x[b].push_back(neg_a);
    adj_x[a].push_back(neg_b);
}

int aabs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

int ssign(int x)
{
    if (x > 0)
    {
        return 1;
    }
    return -1;
}

void Solve()
{
    cin >> n;
    n *= 2;
    adj = vector<vector<int>>(n, vector<int>());
    adj_x = vector<vector<int>>(n, vector<int>());
    int k = 3;
    vector<vector<int>> board(k, vector<int>(n));
    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < n / 2; i++)
        {
            cin >> board[j][i];
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        vector<int> index;
        vector<int> sign;
        for (int j = 0; j < 3; j++)
        {
            index.pb(aabs(board[j][i]) - 1);
            sign.pb(ssign(board[j][i]));
        }

        for (int j = 0; j < 3; j++)
        {
            for (int h = j + 1; h < 3; h++)
            {
                add_disjunction(index[j], sign[j] == -1, index[h], sign[h] == -1);
            }
        }
    }
    int flag = solve_2SAT();
    cout << (flag ? "YES" : "NO") << endl;
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