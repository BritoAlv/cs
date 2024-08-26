// Problem: A. Hayato and School
// Contest: Codeforces - Codeforces Round 846 (Div. 2)
// URL: https://codeforces.com/contest/1780/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define even(x) ((x) % 2 == 0)
#define odd(x) ((x) % 2 == 1)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
    int n;
    cin >> n;
    vi a(n);
    vi o;
    vi e;
    forn
    {
        cin >> a[i];
        if (even(a[i]))
            e.pb(i + 1);
        if (odd(a[i]))
            o.pb(i + 1);
    }
    if (sz(e) >= 2 && sz(o) >= 1)
    {
        cout << "YES" << endl;
        cout << e[0] << wp << e[1] << wp << o[0] << endl;
        return;
    }
    if (sz(o) >= 3)
    {
        cout << "YES" << endl;
        cout << o[0] << wp << o[1] << wp << o[2] << endl;
        return;
    }
    cout << "NO" << endl;
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
