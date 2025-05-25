// Problem: B. Array Recoloring
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/B
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
    int n, k;
    cin >> n >> k;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    ll maxx = max(a[0], a[n - 1]);
    sort(a.begin(), a.end(), greater<ll>());
    if (k >= 2 || maxx == a[0])
    {
        ll ans = 0;
        fori(0, k)
        {
            ans += a[i];
        }
        cout << ans << endl;
    }
    else
    {
        cout << a[0] + maxx << endl;
    }
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
