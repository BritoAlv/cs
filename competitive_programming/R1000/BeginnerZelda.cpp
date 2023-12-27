// Problem: B. Begginer's Zelda
// Contest: Codeforces - Codeforces Round 915 (Div. 2)
// URL: https://codeforces.com/contest/1905/problem/B
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
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> graph;
    forn
    {
        graph.pb(vector<int>());
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int count = 0;
    forn
    {
        if (graph[i].size() == 1)
        {
            count++;
        }
    }
    cout << count / 2 + (count % 2 != 0) << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
