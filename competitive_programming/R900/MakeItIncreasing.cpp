// Problem: B. Make It Increasing
// Contest: Codeforces - Codeforces Round 787 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1675/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: apply operation until increasing from end to start
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int rep(int x, int y)
{
    return (int)log2(x / y) + 1;
}

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= a[i + 1] && a[i + 1] != 0)
        {
            int ops = rep(a[i], a[i + 1]);
            sum += ops;
            a[i] = a[i] >> ops;
        }

        if (a[i] < i || a[i + 1] == 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << sum << endl;
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
