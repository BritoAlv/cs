// Problem: B. Slice to Survive
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/B
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

int log2(int x)
{
    for (ll i = 0; i <= 30; i++)
    {
        ll one = (1 << i);
        ll two = (1 << (i + 1));
        if (one <= x && x <= two)
        {
            return i + (x != one);
        }
    }
}

void Solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    pi one = {n - a + 1, m};
    pi two = {a, m};
    pi three = {n, m - b + 1};
    pi four = {n, b};
    vector<pi> c;
    c.pb(one);
    c.pb(two);
    c.pb(three);
    c.pb(four);
    int ans = 1e9;
    for (auto z : c)
    {
        if (z.first > 0 && z.second > 0)
        {
            ans = min(ans, log2(z.first) + log2(z.second));
        }
    }
    cout << 1 + ans << endl;
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
