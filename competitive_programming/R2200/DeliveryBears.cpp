// Problem: D. Delivery Bears
// Contest: Codeforces - IndiaHacks 2016 - Online Edition (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/653/problem/D
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
#define ull unsigned long long
using namespace std;

int visited_bfs[50];
int pbfs[50];
vector<vector<int>> graph;
double A[50][50];
double B[50][50];
int n, m, k;

void flow_bfs(int a, int sink, double bottleneck)
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
            if (!visited_bfs[x] && A[next][x] >= bottleneck)
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

int get_flow(int n, int p[], double bottleneck)
{
    int actual = n - 1;
    int p_actual = p[n - 1];
    double minn = 1e18;
    while (p_actual != -1)
    {
        minn = min(minn, A[p_actual][actual]);
        actual = p_actual;
        p_actual = p[p_actual];
    }
    int how_many = floor(minn / bottleneck);
    actual = n - 1;
    p_actual = p[n - 1];
    while (p_actual != -1)
    {
        A[p_actual][actual] -= how_many * bottleneck;
        A[actual][p_actual] += how_many * bottleneck;
        actual = p_actual;
        p_actual = p[p_actual];
    }
    return how_many;
}

int flow(double bottleneck)
{
    // check if it's possible that x bears transport
    // bottleneck units of flow from source to sink.
    int works = 1;
    int left_to_find = k;
    while (left_to_find > 0)
    {
        forn
        {
            pbfs[i] = -1;
            visited_bfs[i] = 0;
        }
        flow_bfs(0, n - 1, bottleneck);
        if (pbfs[n - 1] == -1)
        {
            works = 0;
            break;
        }
        left_to_find -= get_flow(n, pbfs, bottleneck);
        ;
    }
    forn
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = B[i][j];
        }
    }
    return works;
}

void Solve()
{
    cin >> n >> m >> k;
    forn
    {
        graph.pb(vector<int>());
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 0;
            B[i][j] = 0;
        }
    }
    form
    {
        int a, b;
        double w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
        A[a][b] += w;
        B[a][b] += w;
    }
    double l_ans = 0;
    double g_ans = 1000000;
    while (g_ans - l_ans > 1e-9)
    {
        double middle = (l_ans + g_ans) / 2;
        if (flow(middle))
        {
            l_ans = middle;
        }
        else
        {
            g_ans = middle;
        }
    }
    cout << setprecision(15) << g_ans * k << endl;
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
