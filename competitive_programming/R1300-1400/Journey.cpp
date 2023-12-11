// Problem: C. Journey
// Contest: Codeforces - Codeforces Round 428 (Div. 2)
// URL: https://codeforces.com/problemset/problem/839/C
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
        graph[a - 1].pb(b - 1);
        graph[b - 1].pb(a - 1);
    }
    double prob[n];
    long long dist[n];
    forn
    {
        dist[i] = -1;
        prob[i] = 1;
    }
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (q.size() > 0)
    {
        auto t = q.front();
        q.pop();
        double count = 0;
        for (auto x : graph[t])
        {
            if (dist[x] == -1)
            {
                count++;
            }
        }
        for (auto x : graph[t])
        {
            if (dist[x] == -1)
            {
                dist[x] = dist[t] + 1;
                prob[x] = prob[t] / (count);
                q.push(x);
            }
        }
    }
    double sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (graph[i].size() == 1)
        {
            sum += dist[i] * prob[i];
        }
    }
    printf("%0.15f\n", sum);
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
