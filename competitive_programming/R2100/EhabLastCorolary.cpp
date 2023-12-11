#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

int p[100000];
int marked[100000];

vector<int> cycle;

void dfs(int n, vector<vector<int>> &graph)
{
    for (auto x : graph[n])
    {
        if (p[x] == -1)
        {
            p[x] = n;
            marked[x] = (marked[n] == 0 ? 1 : 0);
            dfs(x, graph);
        }
        else if (p[n] != x && cycle.size() == 0)
        {
            int start = n;
            while (start != x)
            {
                cycle.pb(start);
                start = p[start];
            }
            cycle.pb(start);
        }
    }
}

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph;
    forn
    {
        graph.pb(vector<int>());
        p[i] = -1;
        marked[i] = -1;
    }
    form
    {
        int a, b;
        cin >> a >> b;
        if (a <= k && b <= k)
        {
            graph[a - 1].pb(b - 1);
            graph[b - 1].pb(a - 1);
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (p[i] == -1)
        {
            p[i] = i;
            marked[i] = 0;
            dfs(i, graph);
        }
    }
    if (cycle.size() > 0)
    {
        cout << 2 << endl;
        cout << cycle.size() << endl;
        for (auto x : cycle)
        {
            cout << x + 1 << wp;
        }
        cout << endl;
    }
    else
    {
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            if (marked[i] == 0)
            {
                count++;
            }
        }
        cout << 1 << endl;
        if (count >= (k + 1) / 2)
        {
            count = (k + 1) / 2;
            for (int i = 0; i < k && count > 0; i++)
            {
                if (marked[i] == 0)
                {
                    cout << i + 1 << wp;
                    count--;
                }
            }
            cout << endl;
        }
        else
        {
            count = (k + 1) / 2;
            for (int i = 0; i < k && count > 0; i++)
            {
                if (marked[i] == 1)
                {
                    cout << i + 1 << wp;
                    count--;
                }
            }
            cout << endl;
        }
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
