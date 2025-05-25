// Problem: A. Cloudberry Jam
// Contest: Codeforces - Educational Codeforces Round 177 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2086/problem/A
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

int work(ll d, ll n)
{
    return d > 0 && ((2 * d * 3) / 4) / 3 == n;
}

void Solve()
{
    ll n;
    cin >> n;
    fori(3 * n, 3 * n + 2)
    {
        for (int j = 4 * i; j <= 4 * i + 3; j++)
        {
            ll exp = j / 6;
            for (ll z = exp - 6; z <= exp + 6; z++)
            {
                if (work(z, n))
                {
                    cout << z << endl;
                    return;
                }
            }
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
