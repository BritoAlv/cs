// Problem: C. Neo's Escape
// Contest: Codeforces - Codeforces Round 1022 (Div. 2)
// URL: https://codeforces.com/contest/2108/problem/C
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
    int n;
    cin >> n;
    vl a(n);
    vl b;
    fori(0, n - 1) cin >> a[i];
    fori(0, n - 1)
    {
        if (i == 0)
            b.pb(a[i]);
        else if (a[i] != b.back())
        {
            b.pb(a[i]);
        }
    }
    n = b.size();
    a = b;
    vector<pi> A;
    fori(0, n - 1) A.pb({a[i], i});
    sort(A.begin(), A.end(), greater<pi>());
    set<int> rc;
    int ans = 0;
    fori(0, n - 1)
    {
        int next_position = A[i].second;
        // how do I know if can be released without cloning ?
        // because there will be a relea.
        auto pt = rc.lower_bound(next_position);
        int flag = 1;
        if (pt == rc.end())
        {
        }
        else
        {
            if (*pt == next_position + 1)
            {
                flag = 0;
            }
        }
        if (pt == rc.begin())
        {
        }
        else
        {
            pt--;
            if (*pt == next_position - 1)
            {
                flag = 0;
            }
        }
        rc.insert(next_position);
        ans += flag;
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