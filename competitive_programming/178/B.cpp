// Problem: B. Move to the End
// Contest: Codeforces - Educational Codeforces Round 178 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2104/problem/B
// Memory Limit: 512 MB
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
    int n;
    cin >> n;
    vi a(n);
    forn cin >> a[i];
    vl s(n);
    vl sol(n);
    vi p(n);
    forn
    {
        p[i] = a[i];
        if (i > 0)
            p[i] = max(p[i], p[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        s[i] = a[i];
        if (i < n - 1)
            s[i] += s[i + 1];
    }
    forn
    {
        sol[i] = p[n - 1 - i];
        if (i > 0)
        {
            sol[i] += s[n - i];
        }
        cout << sol[i] << wp;
    }
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