// Problem: C. Qpwoeirut And The City
// Contest: Codeforces - Codeforces Round 809 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1706/C
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
#define ull unsigned long long

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    if (n % 2 == 1)
    {
        ull ans = 0;
        for (int i = 1; i < n; i += 2)
        {
            ans += max(a[i], max(a[i - 1], a[i + 1]) + 1) - a[i];
        }
        cout << ans << endl;
    }
    else
    {
        ull ans = 1e18;
        ull ssums[n];
        ssums[0] = 0;
        ssums[n - 1] = 0;
        ssums[n - 2] = max(a[n - 2], max(a[n - 3], a[n - 1]) + 1) - a[n - 2];
        for (int i = n - 3; i > 0; i--)
        {
            ssums[i] = ssums[i + 2] + max(a[i], max(a[i - 1], a[i + 1]) + 1) - a[i];
        }
        ull current = 0;
        for (int i = 1; i < n - 1; i += 2)
        {
            // option 1 is that this guy do not win.
            ans = min(ans, ssums[i + 1] + current);
            // option 2 is that this guy wins.
            // so take a current for next round.
            current += max(a[i], max(a[i - 1], a[i + 1]) + 1) - a[i];
        }
        cout << min(ans, current) << endl;
    }
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
