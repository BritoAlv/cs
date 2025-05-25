// Problem: B. Lady Bug
// Contest: Codeforces - Codeforces Round 1014 (Div. 2)
// URL: https://codeforces.com/contest/2092/problem/B
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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int a1 = 0;
    int a2 = 0;
    int b1 = 0;
    int b2 = 0;
    int even = n - n / 2;
    int odd = n - even;
    fori(0, n - 1)
    {
        if (i % 2 == 0)
        {
            a1 += a[i] == '1';
            b1 += b[i] == '1';
        }
        else
        {
            a2 += a[i] == '1';
            b2 += b[i] == '1';
        }
    }
    cout << ((a2 <= even - b1 && a1 <= odd - b2) ? "YES" : "NO") << endl;
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
