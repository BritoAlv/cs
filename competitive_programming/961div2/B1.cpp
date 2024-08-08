// Problem: B1. Bouquet (Easy Version)
// Contest: Codeforces - Codeforces Round 961 (Div. 2)
// URL: https://codeforces.com/contest/1995/problem/B1
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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

void Solve()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> count;
    forn
    {
        ll x;
        cin >> x;
        if (!exist(count, x))
        {
            count[x] = 0;
        }
        count[x]++;
    }
    ll maxx = -1;
    for (auto x : count)
    {
        ll cantidad = min(x.second, m / x.first);
        ll rem = m - cantidad * x.first;
        ll petals = cantidad * x.first;
        // cout << x.first << wp << cantidad << wp << rem << wp << petals << endl;
        if (exist(count, x.first + 1))
        {
            auto xx = *count.find(x.first + 1);
            ll cantidad2 = min(xx.second, rem / xx.first);
            petals += cantidad2 * xx.first;
        }
        if (maxx == -1 || maxx < petals)
        {
            maxx = petals;
        }
    }
    for (auto x : count)
    {
        ll cantidad = min(x.second, m / x.first);
        ll rem = m - cantidad * x.first;
        ll petals = cantidad * x.first;
        // cout << x.first << wp << cantidad << wp << rem << wp << petals << endl;
        if (exist(count, x.first - 1))
        {
            auto xx = *count.find(x.first - 1);
            ll cantidad2 = min(xx.second, rem / xx.first);
            petals += cantidad2 * xx.first;
        }
        if (maxx == -1 || maxx < petals)
        {
            maxx = petals;
        }
    }
    for (auto x : count)
    {
        ll cantidad = min(x.second - 1, m / x.first);
        ll rem = m - cantidad * x.first;
        ll petals = cantidad * x.first;
        // cout << x.first << wp << cantidad << wp << rem << wp << petals << endl;
        if (exist(count, x.first + 1))
        {
            auto xx = *count.find(x.first + 1);
            ll cantidad2 = min(xx.second, rem / xx.first);
            petals += cantidad2 * xx.first;
        }
        if (maxx == -1 || maxx < petals)
        {
            maxx = petals;
        }
    }
    for (auto x : count)
    {
        ll cantidad = min(x.second - 1, m / x.first);
        ll rem = m - cantidad * x.first;
        ll petals = cantidad * x.first;
        // cout << x.first << wp << cantidad << wp << rem << wp << petals << endl;
        if (exist(count, x.first - 1))
        {
            auto xx = *count.find(x.first - 1);
            ll cantidad2 = min(xx.second, rem / xx.first);
            petals += cantidad2 * xx.first;
        }
        if (maxx == -1 || maxx < petals)
        {
            maxx = petals;
        }
    }
    cout << maxx << endl;
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