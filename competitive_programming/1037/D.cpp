// Problem: D. This Is the Last Time
// Contest: Codeforces - Codeforces Round 1037 (Div. 3)
// URL: https://codeforces.com/contest/2126/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    vector<vl> seg(n, vl(3));
    fori(0, n - 1)
    {
        cin >> seg[i][0] >> seg[i][1] >> seg[i][2];
    }
    sort(seg.begin(), seg.end());
    ll big_money = k;
    fori(0, n - 1)
    {
        if (seg[i][0] <= big_money && big_money <= seg[i][1])
            big_money = max(big_money, seg[i][2]);
    }
    cout << big_money << endl;
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
