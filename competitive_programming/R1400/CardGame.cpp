// Problem: D. Card Game
// Contest: Codeforces - Codeforces Round 927 (Div. 3)
// URL: https://codeforces.com/contest/1932/problem/D
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

vector<int> Blossom(vector<vector<int>> &graph)
{
    int n = graph.size(), timer = -1;
    vector<int> mate(n, -1), label(n), parent(n), orig(n), aux(n, -1), q;
    auto lca = [&](int x, int y) {
        for (timer++;; swap(x, y))
        {
            if (x == -1)
                continue;
            if (aux[x] == timer)
                return x;
            aux[x] = timer;
            x = (mate[x] == -1 ? -1 : orig[parent[mate[x]]]);
        }
    };
    auto blossom = [&](int v, int w, int a) {
        while (orig[v] != a)
        {
            parent[v] = w;
            w = mate[v];
            if (label[w] == 1)
                label[w] = 0, q.push_back(w);
            orig[v] = orig[w] = a;
            v = parent[w];
        }
    };
    auto augment = [&](int v) {
        while (v != -1)
        {
            int pv = parent[v], nv = mate[pv];
            mate[v] = pv;
            mate[pv] = v;
            v = nv;
        }
    };
    auto bfs = [&](int root) {
        fill(label.begin(), label.end(), -1);
        iota(orig.begin(), orig.end(), 0);
        q.clear();
        label[root] = 0;
        q.push_back(root);
        for (int i = 0; i < (int)q.size(); ++i)
        {
            int v = q[i];
            for (auto x : graph[v])
            {
                if (label[x] == -1)
                {
                    label[x] = 1;
                    parent[x] = v;
                    if (mate[x] == -1)
                        return augment(x), 1;
                    label[mate[x]] = 0;
                    q.push_back(mate[x]);
                }
                else if (label[x] == 0 && orig[v] != orig[x])
                {
                    int a = lca(orig[v], orig[x]);
                    blossom(x, v, a);
                    blossom(v, x, a);
                }
            }
        }
        return 0;
    };
    // Time halves if you start with (any) maximal matching.
    for (int i = 0; i < n; i++)
        if (mate[i] == -1)
            bfs(i);
    return mate;
}

void print_card(pair<char, int> A)
{
    cout << A.second << A.first << wp;
}

char tr;

int is_less(pair<char, int> A, pair<char, int> B)
{
    if (A.first == B.first)
    {
        return A.second < B.second;
    }
    else
    {
        return B.first == tr;
    }
}

void Solve()
{
    int n;
    cin >> n;
    int m = 2 * n;
    cin >> tr;
    vector<vector<int>> edges;
    form
    {
        edges.pb(vector<int>());
    }
    vector<pair<char, int>> C;
    form
    {
        int c;
        char t;
        cin >> c >> t;
        C.pb({t, c});
    }
    form
    {
        for (int i = 0; i < m; i++)
        {
            if (i != j)
            {
                if (is_less(C[j], C[i]))
                {
                    edges[j].pb(i);
                    edges[i].pb(j);
                }
            }
        }
    }
    vector<int> result = Blossom(edges);
    for (auto x : result)
    {
        if (x == -1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    set<int> used;
    form
    {
        if (used.find(j) == used.end())
        {
            used.insert(j);
            used.insert(result[j]);
            auto card_one = C[j];
            auto card_two = C[result[j]];
            if (is_less(card_one, card_two))
            {
                print_card(card_one);
                print_card(card_two);
            }
            else
            {
                print_card(card_two);
                print_card(card_one);
            }
            cout << endl;
        }
    }
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
