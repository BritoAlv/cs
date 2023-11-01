// Problem: A. Increasing and Decreasing
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1864/problem/A
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
    int x, y, n;
    cin >> x >> y >> n;
    int a[n];
    a[n - 1] = y;
    for (int i = n - 2; i >= 0; i--)
    {
        a[i] = a[i + 1] - (n - 1 - i);
    }
    a[0] = min(x, a[0]);
    if (a[0] < x)
    {
        cout << -1 << endl;
    }
    else
    {
        forn
        {
            cout << a[i] << wp;
        }
        cout << endl;
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
