// Problem: E. Tree Constructing
// Contest: Codeforces - Codeforces Round 494 (Div. 3)
// URL: https://codeforces.com/contest/1003/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

int next_to_add;
int n, d, k;
vector<vector<int>> graph;

void construct_tree(int root, int max_depth, int rem_degree)
{
    queue<pair<int, int>> cola;
    for (int i = 0; i < rem_degree; i++)
    {
        if (max_depth > 0 && next_to_add < n)
        {
            graph[root].pb(next_to_add);
            cola.push({next_to_add, 1});
            next_to_add++;
        }
        else
        {
            return;
        }
    }
    while (cola.size() > 0)
    {
        auto next = cola.front();
        cola.pop();
        for (int i = 0; i < k - 1; i++)
        {
            if (next_to_add >= n || next.second == max_depth)
            {
                return;
            }
            else
            {
                graph[next.first].pb(next_to_add);
                cola.push({next_to_add, next.second + 1});
                next_to_add++;
            }
        }
    }
    return;
}

void Solve()
{
    cin >> n >> d >> k;
    if (d + 1 > n)
    {
        cout << "NO" << endl;
        return;
    }
    forn
    {
        graph.pb(vector<int>());
    }
    next_to_add = d + 1;
    for (int i = 0; i < d; i++)
    {
        graph[i].pb(i + 1);
    }
    for (int i = 0; i < d && next_to_add < n; i++)
    {
        int max_depth = min(i, d - i);
        construct_tree(i, max_depth, k - 2);
    }
    int n_edges = 0;
    int degrees[n];
    forn
    {
        degrees[i] = 0;
    }
    forn
    {
        for (auto x : graph[i])
        {
            degrees[x]++;
        }
        degrees[i] += graph[i].size();
        n_edges += graph[i].size();
    }
    forn
    {
        if (degrees[i] > k)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (n_edges == n - 1)
    {
        cout << "YES" << endl;
        forn
        {
            for (auto x : graph[i])
            {
                cout << i + 1 << wp << x + 1 << endl;
            }
        }
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
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