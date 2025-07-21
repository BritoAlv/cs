// Problem: B. No Casino in the Mountains
// Contest: Codeforces - Codeforces Round 1037 (Div. 3)
// URL: https://codeforces.com/contest/2126/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void Solve()
{
    int n, k;
    cin >> n >> k;
    vl a(n + 1);
    a[n] = 1;
    fori(0, n - 1) cin >> a[i];
    int ans = 0;
    int zeros = 0;
    fori(0, n)
    {
        if (a[i])
        {
            int rem = zeros % (k + 1);
            int to_add = zeros / (k + 1);
            ans += to_add;
            // cout << i << wp << rem << wp << to_add << endl;
            if (rem == k)
                ans++;
            zeros = 0;
        }
        else
        {
            zeros++;
        }
    }
    cout << ans << endl;
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
