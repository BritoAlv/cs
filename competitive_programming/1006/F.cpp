// Problem: F. Goodbye, Banker Life
// Contest: Codeforces - Codeforces Round 1006 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2072/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags:
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

int test_cases;
using namespace std;

ll dp(int n, int i)
{
    if (n == 1 && i == 1)
        return 1;
    if (i == 1 || i == n)
        return 1ll;
    if (i > n)
        return 0ll;
    int k = 0;
    while (n > (1ll << (k + 1)))
    {
        k++;
    }
    if (n == (1 << (k + 1)))
    {
        return 1;
    }
    // cout << n << wp << k << endl;
    if (i > (1ll << k))
        i -= (1ll << k);
    n = n % (1ll << k);
    // cout << n << wp << i << endl;
    return dp(n, i);
}

void Solve()
{
    int n;
    ll k;
    cin >> n >> k;
    fori(0, n - 1) cout << k * dp(n, i + 1) << wp;
    cout << endl;
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
