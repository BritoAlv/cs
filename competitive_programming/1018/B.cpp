// Problem: B. Wonderful Gloves
// Contest: Codeforces - Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2096/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n, k;
    cin >> n >> k;
    vector<pair<ll, int>> l(n), r(n);
    vector<pair<ll, int>> c(n);
    fori(0, n - 1)
    {
        cin >> l[i].first;
        l[i].second = i;
    }
    fori(0, n - 1)
    {
        cin >> r[i].first;
        r[i].second = i;
    }
    ll sum = 0;
    vector<ll> pending;
    fori(0, n - 1)
    {
        sum += max(l[i].first, r[i].first);
        pending.pb(min(l[i].first, r[i].first));
    }
    sort(pending.begin(), pending.end(), greater<ll>());
    fori(0, k - 2)
    {
        sum += pending[i];
    }
    cout << sum + 1 << endl;
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