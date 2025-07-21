// Problem: C. I Will Definitely Make It
// Contest: Codeforces - Codeforces Round 1037 (Div. 3)
// URL: https://codeforces.com/contest/2126/problem/C
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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    set<ll> heights;
    fori(0, n - 1) if (a[i] > a[k - 1]) heights.insert(a[i]);
    ll cur_level = 0;
    ll cur_height = a[k - 1];
    while (heights.size() > 0)
    {
        // cout << cur_level << wp << cur_height << endl;
        ll next = *heights.begin();
        heights.erase(heights.begin());
        cur_level += next - cur_height;
        if (cur_level > cur_height)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cur_height = next;
        }
    }
    cout << "YES" << endl;
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
