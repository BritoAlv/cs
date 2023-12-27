// Problem: C. Scoring Subsequences
// Contest: Codeforces - Codeforces Round 856 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1794/C
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
    int n;
    cin >> n;
    int a[n];
    int r[n];
    forn
    {
        cin >> a[i];
    }

    r[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - r[i - 1]] > r[i - 1])
        {
            r[i] = r[i - 1] + 1;
        }
        else
        {
            r[i] = r[i - 1];
        }
    }
    forn
    {
        cout << r[i] << wp;
    }
    cout << endl;
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
