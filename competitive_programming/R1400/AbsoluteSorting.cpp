// Problem: D. Absolute Sorting
// Contest: Codeforces - Codeforces Round 839 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1772/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
    int minn = 0;
    int maxx = 1e9;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            maxx = min(maxx, (a[i] + a[i - 1]) / 2);
        }
        if (a[i] < a[i - 1])
        {
            minn = max(minn, (a[i] + a[i - 1]) / 2 + (a[i] + a[i - 1]) % 2);
        }
    }
    if (minn <= maxx)
    {
        cout << minn << endl;
    }
    else
    {
        cout << -1 << endl;
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
