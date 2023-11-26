// Problem: C. Underground Lab
// Contest: Codeforces - Codeforces Round 403 (Div. 1, based on Technocup 2017 Finals)
// URL: https://codeforces.com/contest/781/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

int d[200000];
vector<int> klones;
void dfs_visit(int n, vector<vector<int>> &graph)
{
    klones.pb(n);
    d[n] = 0;
    for (auto x : graph[n])
    {
        if (d[x] == -1)
        {
            dfs_visit(x, graph);
            klones.pb(n);
        }
    }
}

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
        graph.pb(vector<int>());
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }

    forn
    {
        d[i] = -1;
    }

    dfs_visit(0, graph);

    int upper = (2 * n) / k + ((2 * n) % k != 0);
    int counter = 0;
    int used = 0;
    int at_most_k = 0;
    for (int i = 0; i < klones.size(); i++, used++)
    {
        if (counter == 0)
        {
            cout << min((int)klones.size() - used, upper) << wp;
        }
        cout << klones[i] + 1 << wp;
        counter++;
        if (counter == upper)
        {
            counter = 0;
            at_most_k++;
            cout << endl;
        }
    }
    if (klones.size() % upper != 0)
    {
        at_most_k++;
    }
    while (at_most_k < k)
    {
        cout << 1 << wp << 1 << endl;
        at_most_k++;
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
