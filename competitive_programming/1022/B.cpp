// Problem: B. SUMdamental Decomposition
// Contest: Codeforces - Codeforces Round 1022 (Div. 2)
// URL: https://codeforces.com/contest/2108/problem/B
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
    int n, x;
    cin >> n >> x;
    int copy_x = x;
    vi bits;
    int on = 0;
    while (x > 0)
    {
        bits.pb(x % 2);
        on += x % 2;
        x /= 2;
    }
    if (on >= n)
    {
        cout << copy_x << endl; // ok
    }
    else if ((n - on) % 2 == 0)
    {
        cout << copy_x + (n - on) << endl;
    }
    else if (on >= 2)
    {
        cout << copy_x + (n - on) + 1 << endl;
    }
    else if (on == 1)
    {
        // only a bit on.
        // n is even.
        if (copy_x % 2 == 0)
        {
            cout << (copy_x + 1) + (n - 1) << endl;
        }
        else
        {
            cout << (copy_x + 2) + 2 + (n - 2) << endl;
        }
    }
    else
    {
        // no bits on.
        if (n % 2 == 0)
        {
            cout << n << endl;
        }
        else
        {
            if (n == 1)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << 6 + (n - 3) << endl;
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
