// Problem: C. Two Colors
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

void Solve()
{
    ll n, m;
    cin >> n >> m;
    vl a(m);
    fori(0, m - 1) cin >> a[i];
    fori(0, m - 1) a[i] = min(n - 1, a[i]);
    vl pref(n);
    vl pref2(n);
    fori(0, m - 1) pref[n - a[i]]++;
    fori(1, n - 1) pref[i] += pref[i - 1];

    fori(0, m - 1) pref2[n - a[i]]++;
    fori(0, n - 1) pref2[i] *= (long long)(i);
    fori(1, n - 1) pref2[i] += pref2[i - 1];

    vl ans(m);
    fori(0, m - 1)
    {
        ll less = pref[a[i]];
        ans[i] += (a[i] + 1) * less;
        ans[i] -= pref2[a[i]];

        if (n - a[i] <= a[i])
        {
            ans[i] -= (a[i] + 1 - (n - a[i]));
        }
    }
    ll b = 0;
    fori(0, m - 1)
    {
        b += ans[i];
        // cout << ans[i] << wp;
    }
    // cout << endl;
    cout << b << endl;
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
