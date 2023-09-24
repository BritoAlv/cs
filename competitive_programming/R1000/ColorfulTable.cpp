// Problem: C. Colorful Table
// Contest: Codeforces - CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1870/problem/C
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
    int n, k;
    cin >> n >> k;

    int a[n];
    forn
    {
        cin >> a[i];
    }

    int max_watched = 0;

    int b[k];
    int c[k];
    int d[k + 1];
    for (int i = 0; i <= k; i++)
    {
        d[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        b[i] = 0;
        c[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        d[a[i]] = 1;
        for (int t = a[i]; t > max_watched; t--)
        {
            b[t - 1] = i;
        }
        if (a[i] > max_watched)
        {
            max_watched = a[i];
        }
    }

    max_watched = 0;
    for (int i = 0; i < n; i++)
    {
        for (int t = a[i]; t > max_watched; t--)
        {
            c[t - 1] = i;
        }
        if (a[i] > max_watched)
        {
            max_watched = a[i];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        if (d[i] == 1)
        {
            cout << 2 * (b[i - 1] - c[i - 1] + 1) << wp;
        }
        else
        {
            cout << 0 << wp;
        }
    }
    cout << endl;
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