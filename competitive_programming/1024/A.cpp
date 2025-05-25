// Problem: A. Dinner Time
// Contest: Codeforces - Codeforces Round 1024 (Div. 2)
// URL: https://codeforces.com/contest/2102/problem/0
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
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p != 0)
    {
        int ex_sum = q * n / p;
        int rem_sum = m - ex_sum;
        vi b(n);
        for (int i = 0; i < n; i++)
        {
            if (i % p == 0)
                b[i] = rem_sum;
            if (i % p == p - 1)
            {
                b[i] = q - rem_sum;
            }
        }
        cout << "YES" << endl;
    }
    else
    {
        if (m != ((n / p) * q))
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            vi b(n);
            for (int i = 0; i < n; i++)
            {
                if (i % p == 0)
                    b[i] = q;
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
