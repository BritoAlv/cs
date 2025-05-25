// Problem: A. Was there an Array?
// Contest: Codeforces - Educational Codeforces Round 174 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2069/problem/A
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

void Solve()
{
    int n;
    cin >> n;
    vl a(n - 2);
    fori(0, n - 3) cin >> a[i];
    fori(1, n - 4)
    {
        if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1)
        {
            cout << "NO" << endl;
            return;
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
