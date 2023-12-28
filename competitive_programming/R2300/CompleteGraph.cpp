// Problem: B. Complete The Graph
// Contest: Codeforces - Codeforces Round 372 (Div. 1)
// URL: https://codeforces.com/problemset/problem/715/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Math Proof:
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
#define inf 1000000000000000000
using namespace std;

map<pair<int, int>, ull> weights;

ull get_weight(int x, int y)
{
    return weights[{min(x, y), max(x, y)}];
}

void set_weight(int x, int y, ull w)
{
    weights[{min(x, y), max(x, y)}] = w;
}

vector<vector<int>> graph;

ull d[1000];
int p[1000];

void dikstra(int n, int s, ull mw)
{
    forn
    {
        d[i] = inf;
    }
    d[s] = 0;
    set<pair<ull, int>> PQ;
    forn
    {
        p[i] = -1;
        PQ.insert({d[i], i});
    }
    while (PQ.size() > 0)
    {
        auto next = *(PQ.begin());
        PQ.erase(next);
        for (auto z : graph[next.second])
        {
            ull q_w = get_weight(next.second, z);
            if (q_w == 0)
            {
                q_w = mw;
            }
            if (d[z] > d[next.second] + q_w)
            {
                PQ.erase({d[z], z});
                d[z] = d[next.second] + q_w;
                p[z] = next.second;
                PQ.insert({d[z], z});
            }
        }
    }
}

void Solve()
{
    int n, m;
    ull L;
    int a, b;
    cin >> n >> m >> L >> a >> b;
    forn
    {
        graph.pb(vector<int>());
    }
    form
    {
        int c, d;
        ull w;
        cin >> c >> d >> w;
        graph[c].pb(d);
        graph[d].pb(c);
        set_weight(c, d, w);
    }
    int w_start = 1;
    int w_end = L;
    while (w_end - w_start > 1)
    {
        int middle = (w_start + w_end) / 2;
        dikstra(n, a, middle);
        if (d[b] > L)
        {
            w_end = middle;
        }
        else
        {
            w_start = middle;
        }
    }
    dikstra(n, a, w_start);
    if (d[b] > L)
    {
        cout << "NO" << endl;
    }
    else if (d[b] == L)
    {
        cout << "YES" << endl;
        for (auto x : weights)
        {
            cout << x.first.first << wp << x.first.second << wp << (x.second == 0 ? w_start : x.second) << endl;
        }
    }
    else
    {
        vector<pair<int, int>> path;
        int actual = b;
        while (p[actual] != -1)
        {
            path.pb({actual, p[actual]});
            actual = p[actual];
        }
        int number_special = 0;
        for (auto x : path)
        {
            if (get_weight(x.first, x.second) == 0)
            {
                number_special++;
            }
        }
        if (number_special == 0)
        {
            cout << "NO" << endl;
            return;
        }
        int assigned = 0;
        ull to_distribute = L - d[b] + w_start * number_special;
        ull rem = to_distribute;
        for (auto x : path)
        {
            if (get_weight(x.first, x.second) == 0)
            {
                if (assigned != number_special - 1)
                {
                    set_weight(x.first, x.second, to_distribute / number_special);
                    rem -= to_distribute / number_special;
                }
                else
                {
                    set_weight(x.first, x.second, rem);
                }
                assigned++;
            }
        }
        for (auto x : weights)
        {
            if (get_weight(x.first.first, x.first.second) == 0)
            {
                set_weight(x.first.first, x.first.second, inf);
            }
        }
        dikstra(n, a, inf);
        if (d[b] == L)
        {
            cout << "YES" << endl;
            for (auto x : weights)
            {
                cout << x.first.first << wp << x.first.second << wp << x.second << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
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
