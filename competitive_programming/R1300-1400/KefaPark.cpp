// Problem: C. Kefa and Park
// Contest: Codeforces - Codeforces Round 321 (Div. 2)
// URL: https://codeforces.com/contest/580/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

int c[100000];
int d[100000];

int n, max_cats;
int answer;
void dfs_visit(int k, int cat_before, vector<vector<int>> &graph)
{
    if (c[k] == 0)
    {
        d[k] = 0;
    }
    else
    {
        d[k] = cat_before + 1;
    }
    if (d[k] > max_cats)
    {
        return;
    }
    int count = 0;
    for (auto x : graph[k])
    {
        if (d[x] == -1)
        {
            count++;
            dfs_visit(x, d[k], graph);
        }
    }
    if (count == 0)
    {
        answer++;
    }
    return;
}

void Solve()
{
    cin >> n >> max_cats;
    forn
    {
        cin >> c[i];
        d[i] = -1;
    }
    vector<vector<int>> graph;
    forn
    {
        graph.pb(vector<int>());
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }
    answer = 0;
    dfs_visit(0, 0, graph);
    cout << answer << endl;
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
