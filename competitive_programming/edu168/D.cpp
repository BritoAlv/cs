// Problem: D. Maximize the Root
// Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1997/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
#define print(x, name)                                                                                                 \
    cout << name << endl;                                                                                              \
    for (auto z : x)                                                                                                   \
        cout << z << wp;                                                                                               \
    cout << endl;
// je m appelle Alvaro j ai 21 ans.
int test_cases;
int test_cases_original;
#define t_number test_cases_original - test_cases

using namespace std;

ll solve(int st, vector<ll> &a, vector<vi> &graph)
{
    ll minn = -1;
    for (auto x : graph[st])
    {
        auto rs = solve(x, a, graph);
        if (minn == -1 || minn > rs)
        {
            minn = rs;
        }
    }
    int ans;
    if (minn == -1)
    {
        ans = a[st];
    }
    else if (a[st] > minn)
    {
        ans = minn;
    }
    else
    {
        ans = (a[st] + minn) / 2;
    }
    return ans;
}

void Solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    forn
    {
        cin >> a[i];
    }
    vector<vi> graph(n, vi());
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        graph[x - 1].pb(i + 1);
    }
    ll minn = -1;
    for (auto x : graph[0])
    {
        auto ts = solve(x, a, graph);
        if (minn == -1 || ts < minn)
        {
            minn = ts;
        }
    }
    if (minn == -1)
    {
        minn = 0;
    }
    cout << a[0] + minn;
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> test_cases_original;
    test_cases = test_cases_original;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
