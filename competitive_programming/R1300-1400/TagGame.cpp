// Problem: C. The Tag Game
// Contest: Codeforces - Educational Codeforces Round 22
// URL: https://codeforces.com/contest/813/problem/C
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

void Solve()
{
    int n, x;
    cin >> n >> x;
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
    int d1[n];
    int d2[n];
    forn
    {
        d1[i] = -1;
        d2[i] = -1;
    }
    d1[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size() > 0)
    {
        auto top = q.front();
        q.pop();
        for (auto y : graph[top])
        {
            if (d1[y] == -1)
            {
                d1[y] = 1 + d1[top];
                q.push(y);
            }
        }
    }
    d2[x - 1] = 0;
    q.push(x - 1);
    while (q.size() > 0)
    {
        auto top = q.front();
        q.pop();
        for (auto y : graph[top])
        {
            if (d2[y] == -1)
            {
                d2[y] = 1 + d2[top];
                q.push(y);
            }
        }
    }
    int minn = 2 * d1[x - 1];
    for (int i = 0; i < n; i++)
    {
        if (d2[i] < d1[i])
        {
            minn = max(minn, 2 * d1[i]);
        }
    }
    cout << minn << endl;
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
