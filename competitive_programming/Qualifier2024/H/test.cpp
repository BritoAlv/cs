#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

#define ld __float128

/*
assume that every variable appears at least once, in the equations.
*/
vector<ld> gauss(vector<vector<ld>> &mx)
{
    int n_equations = (int)mx.size();
    int n_variables = (int)mx[0].size() - 1;
    for (int i = 0; i < n_variables; i++)
    {
        /*
        for each variable find the column with largest absolute value and swap it with actual.
        */
        int pos = i;
        for (int j = i + 1; j < n_equations; j++)
        {
            auto one = mx[j][i];
            auto sec = mx[pos][i];
            if(one < 0)
            {
                one *= -1;
            }
            if(sec < 0)
            {
                sec *= -1;
            }
            if (one > sec)
            {
                pos = j;
            }
        }
        for (int j = 0; j < n_variables + 1; j++)
        {
            ld temp = mx[i][j];
            mx[i][j] = mx[pos][j];
            mx[pos][j] = temp;
        }
        /*
        assume that the absolute value is greater than zero.
        */
        ld now = mx[i][i];
        for (int j = 0; j < n_variables + 1; j++)
        {
            mx[i][j] /= now;
        }
        for (int j = 0; j < n_equations; j++)
        {
            if (j != i)
            {
                ld now = mx[j][i];
                for (int k = 0; k < n_variables + 1; k++)
                {
                    mx[j][k] -= (mx[i][k] * now);
                }
            }
        }
    }
    vector<ld> ret;
    for (int i = 0; i < n_variables; i++)
    {
        ret.pb(mx[i][n_variables]);
    }
    return ret;
}

const int INF = 1e9;

vector<int> distances(int s, vector<vector<int>> g)
{
    int n = g.size();
    vector<int> d = vector<int>(n, INF);
    d[s] = 0;
    set<pair<int, int>> PQ;
    forn
    {
        PQ.insert({d[i], i});
    }
    while (PQ.size() > 0)
    {
        auto next = *(PQ.begin());
        PQ.erase(next);
        for (auto z : g[next.second])
        {
            int q_w = 1;
            if (d[z] > d[next.second] + q_w)
            {
                PQ.erase({d[z], z});
                d[z] = d[next.second] + q_w;
                PQ.insert({d[z], z});
            }
        }
    }
    return d;
}

void solve()
{
    int n, g, k;
    cin >> n >> g >> k;
    g--;
    int input_n = n;
    vector<pair<int, int>> input;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        input.pb({a, b});
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vector<int> d = distances(g, graph);
    if (d[0] == INF)
    {
        cout << "NO ROUTE" << endl;
        return;
    }

    map<int, int> new_sys;
    map<int, int> rev;
    int pt = 0;
    forn
    {
        if (d[i] != INF)
        {
            rev[i] = pt;
            new_sys[pt++] = i;
        }
    }
    n = new_sys.size();

    vector<vector<ld>> system(n, vector<ld>(n + 1));
    forn
    {
        if (i != rev[g])
        {
            int original = new_sys[i];
            system[i][i] = graph[original].size();
            int dist = d[original];
            for (auto x : graph[original])
            {
                system[i][rev[x]] = -1;
                if (d[x] >= d[original])
                    system[i][n] += 1;
            }
        }
        else
        {
            system[i][i] = 1;
            system[i][n] = 0;
        }
    }
    auto solution = gauss(system);
    auto ans = (long double)solution[0];
    auto rounded = round(ans * 1000) / 1000;
    cout << std::fixed << std::setprecision(3) << rounded << endl;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        solve();
    }
}