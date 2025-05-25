// Problem: C. Asuna and the Mosquitoes
// Contest: Codeforces - Codeforces Round 1014 (Div. 2)
// URL: https://codeforces.com/contest/2092/problem/C
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
    fori(0, n - 1) cin >> a[i];
    int odds = 0;
    ll sum = 0;
    fori(0, n - 1) sum += a[i];
    fori(0, n - 1) odds += a[i] % 2;
    if (odds > 0 && odds < n)
    {
        cout << sum - odds + 1 << endl;
    }
    else
    {
        ll maxx = a[0];
        fori(0, n - 1) maxx = max(a[i], maxx);
        cout << maxx << endl;
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
