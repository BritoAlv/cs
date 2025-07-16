// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

template <typename K, typename V> void print(const std::map<K, V> &m)
{
    for (const auto &[key, value] : m)
    {
        std::cout << key << ": " << value << "\n";
    }
}

int test_cases;
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<set<int>> adj(n, set<int>());
    fori(0, n - 2)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vi d(n);
    fori(0, n - 1)
    {
        d[i] = adj[i].size();
    }
    vector<pi> T;
    int ans = 0;
    set<pi> V;
    fori(0, n - 1)
    {
        V.insert({-d[i], i});
    }
    fori(0, n - 1)
    {
        V.erase({-d[i], i});
        for (auto v : adj[i])
        {
            ans = max(ans, d[i] + d[v] - 2);
            V.erase({-d[v], v});
        }
        if (V.size() > 0)
        {
            pi first = *V.begin();
            ans = max(ans, d[i] + d[first.second] - 1);
        }
        V.insert({-d[i], i});
        for (auto v : adj[i])
        {
            V.insert({-d[v], v});
        }
    }

    cout << ans << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
