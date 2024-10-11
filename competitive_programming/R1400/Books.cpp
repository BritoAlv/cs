// Problem: B. Books
// Contest: Codeforces - Codeforces Round 171 (Div. 2)
// URL: https://codeforces.com/contest/279/problem/B
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
    int n, t;
    cin >> n >> t;
    vi a(n);
    forn
    {
        cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }
    int asn = 0;
    set<pi> R;
    for (int i = n - 1; i >= 0; i--)
    {
        int tt = (i > 0 ? a[i - 1] : 0);
        R.insert({a[i], i});
        auto pt = R.lower_bound({tt + t + 1, -1});
        if (pt != R.begin())
        {
            pt--;
            if ((*pt).first <= tt + t)
            {
                asn = max(asn, (*pt).second - i + 1);
            }
        }
    }
    cout << asn << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
