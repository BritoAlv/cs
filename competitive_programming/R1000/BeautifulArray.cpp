// Problem: B. Beautiful Array
// Contest: Codeforces - Codeforces Round 816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    long long n, k, b, s;
    cin >> n >> k >> b >> s;
    if (s >= b * k && s <= b * k + n * (k - 1))
    {
        long long a[n];
        forn
        {
            a[i] = 0;
        }
        a[n - 1] = b * k;
        s -= b * k;
        int i = n - 1;
        while (s > 0)
        {
            a[i] += min(s, k - 1);
            i--;
            s -= min(s, k - 1);
        }
        forn
        {
            cout << a[i] << wp;
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
