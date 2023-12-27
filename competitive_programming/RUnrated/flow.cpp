#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

int pbfs[500];
int pdfs[500];
int visited_bfs[500];
int visited_dfs[500];
long long A[500][500];

vector<vector<int>> graph;

void bfs(int a, int sink)
{
    queue<int> q;
    q.push(0);
    visited_bfs[0] = 1;
    while (q.size() > 0)
    {
        auto next = q.front();
        q.pop();
        for (auto x : graph[next])
        {
            if (!visited_bfs[x] && A[next][x] > 0)
            {
                pbfs[x] = next;
                visited_bfs[x] = 1;
                if (x == sink)
                {
                    return;
                }
                q.push(x);
            }
        }
    }
}

void dfs(int a, int sink)
{
    if (a == sink)
    {
        return;
    }
    else
    {
        for (auto x : graph[a])
        {
            if (!visited_dfs[x] && A[a][x] > 0)
            {
                pdfs[x] = a;
                visited_dfs[x] = true;
                dfs(x, sink);
            }
        }
    }
}

int get_flow(int n, int p[])
{
    int actual = n - 1;
    int p_actual = p[n - 1];
    long long minn = 1e9;
    while (p_actual != -1)
    {
        minn = min(minn, A[p_actual][actual]);
        actual = p_actual;
        p_actual = p[p_actual];
    }

    actual = n - 1;
    p_actual = p[n - 1];
    while (p_actual != -1)
    {
        A[p_actual][actual] -= minn;
        A[actual][p_actual] += minn;
        actual = p_actual;
        p_actual = p[p_actual];
    }
    return minn;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    forn
    {
        graph.pb(vector<int>());
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0;
        }
    }
    form
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
        A[a][b] += w;
    }
    long long max_flow = 0;
    while (true)
    {
        forn
        {
            pbfs[i] = -1;
            visited_bfs[i] = 0;
        }

        bfs(0, n - 1);
        if (pbfs[n - 1] == -1)
        {
            break;
        }
        else
        {
            max_flow += get_flow(n, pbfs);
        }
    }
    cout << max_flow << endl;
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
