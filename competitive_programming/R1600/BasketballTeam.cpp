// Problem: B. Basketball Team
// Contest: Codeforces - Codeforces Beta Round 83 (Div. 1 Only)
// URL: https://codeforces.com/problemset/problem/107/B
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
#define pb push_back

using namespace std;

void Solve()
{
    long long n, m, h;
    cin >> n >> m >> h;
    long long total = 0;
    long long a[m];
    form
    {
        cin >> a[j];
        total += a[j];
    }
    if (total < n)
    {
        cout << -1 << endl;
        return;
    }
    long long x = a[h - 1];
    long long y = n - 1;
    long long t = total;
    long double ans = 1;

    long long start1 = t - x - y + 1;
    long long start2 = t - 1 - y + 1;
    while (start1 <= t - x && start2 <= t - 1)
    {
        ans *= (long double)start1 / (long double)start2;
        start1++;
        start2++;
    }

    while (start1 <= t - x)
    {
        ans *= (start1);
        start1++;
    }

    while (start2 <= t - 1)
    {
        ans *= (start2);
        start2++;
    }

    cout << 1 - ans << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}