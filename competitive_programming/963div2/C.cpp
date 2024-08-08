// Problem: C. Light Switches
// Contest: Codeforces - Codeforces Round 963 (Div. 2)
// URL: https://codeforces.com/contest/1993/problem/C
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

pi intt(pi A, pi B)
{
    return {max(A.first, B.first), min(A.second, B.second)};
}

void Solve()
{
    ll n, k;
    cin >> n >> k;
    vector<pi> segments1;
    vector<pi> segments2;
    vl a(n);
    forn
    {
        cin >> a[i];
        int st = (a[i]) % (2 * k);
        if (st == 0)
        {
            segments1.pb({0, k - 1});
            segments2.pb({1e9 + 1, 1e9 + 1});
        }
        else if (st == k)
        {
            segments2.pb({k, 2 * k - 1});
            segments1.pb({1e9 + 1, 1e9 + 1});
        }
        else if (st > k)
        {
            segments1.pb({0, (st + k - 1) % (2 * k)});
            segments2.pb({st, 2 * k - 1});
        }
        else
        {
            segments1.pb({st, k - 1});
            segments2.pb({k, (st + k - 1) % (2 * k)});
        }
    }
    ll maxx = 0;
    auto umax = [&maxx](ll cd) -> void { maxx = max(cd, maxx); };
    forn
    {
        umax(a[i]);
    }
    for (int i = 1; i < segments1.sz; i++)
    {
        segments1[0] = intt(segments1[0], segments1[i]);
    }
    for (int i = 1; i < segments2.sz; i++)
    {
        segments2[0] = intt(segments2[0], segments2[i]);
    }
    set<ll> valids;
    if (segments1.sz > 0)
    {
        for (int i = segments1[0].first; i <= segments1[0].second; i++)
        {
            valids.insert(i);
        }
    }
    if (segments2.sz > 0)
    {
        for (int i = segments2[0].first; i <= segments2[0].second; i++)
        {
            valids.insert(i);
        }
    }
    if (valids.sz == 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < k; i++)
    {
        ll curr = maxx + i;
        if (exist(valids, curr % (2 * k)))
        {
            cout << curr << endl;
            return;
        }
    }
    cout << -1 << endl;
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
