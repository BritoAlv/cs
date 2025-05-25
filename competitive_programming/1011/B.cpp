// Problem: B. Serval and Final MEX
// Contest: Codeforces - Codeforces Round 1011 (Div. 2)
// URL: https://codeforces.com/contest/2085/problem/B
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

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    vi zeros;
    fori(0, n - 1) if (a[i] == 0) zeros.pb(i);
    if (zeros.size() == 0)
    {
        cout << 1 << endl;
        cout << 1 << wp << n << endl;
    }
    else if (zeros.size() == 1)
    {
        int pos = zeros[0];
        if (pos > 0)
        {
            cout << 2 << endl;
            cout << pos << wp << pos + 1 << endl;
            cout << 1 << wp << (n - 1) << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << pos + 1 << wp << pos + 2 << endl;
            cout << 1 << wp << (n - 1) << endl;
        }
    }
    else
    {
        if (zeros.back() != n - 1)
        {
            cout << 2 << endl;
            cout << 1 << wp << zeros.back() + 1 << endl;
            cout << 1 << wp << (n - zeros.back()) << endl;
        }
        else
        {
            int prev = zeros.back();
            int prev_prev = zeros[zeros.size() - 2];
            if (zeros.size() == 2 && prev - 1 == prev_prev)
            {
                cout << 2 << wp << endl;
                cout << n - 1 << wp << n << endl;
                cout << 1 << wp << n - 1 << endl;
            }
            else if (prev - 1 == prev_prev)
            {
                cout << 3 << wp << endl;
                cout << prev_prev + 1 << wp << n << endl;
                cout << 1 << wp << prev_prev << endl;
                cout << 1 << wp << 2 << endl;
            }
            else
            {
                cout << 3 << wp << endl;
                cout << n - 1 << wp << n << endl;
                cout << 1 << wp << n - 2 << endl;
                cout << 1 << wp << 2 << endl;
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
