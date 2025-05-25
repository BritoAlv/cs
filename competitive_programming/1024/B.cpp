// Problem: B. The Picky Cat
// Contest: Codeforces - Codeforces Round 1024 (Div. 2)
// URL: https://codeforces.com/contest/2102/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
// je m appelle Alvaro j ai 22 ans.
int test_cases;
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn cin >> a[i];
    int always_less = 0;
    int always_great = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) < abs(a[0]))
        {
            always_less++;
        }
        if (abs(a[i]) > -abs(a[0]))
        {
            always_great++;
        }
    }
    cout << always_less << wp << always_great << endl;
    if (always_less <= n / 2 || always_great <= n / 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
