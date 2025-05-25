// Problem: B. Large Array and Segments
// Contest: Codeforces - Educational Codeforces Round 177 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2086/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
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
    ll n, k, x;
    cin >> n >> k >> x;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    ll sum = 0;
    ll big_sum = 0;
    fori(0, n - 1) sum += a[i];
    big_sum = sum * k;
    if (big_sum < x)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = n * ((x - 1) / sum);
    ll cur_sum = sum * ((x - 1) / sum);
    for (int i = n - 1; i >= 0; i--)
    {
        cur_sum += a[i];
        if (cur_sum >= x)
        {
            cout << n * k - ans << endl;
            return;
        }
        else
        {
            ans++;
        }
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