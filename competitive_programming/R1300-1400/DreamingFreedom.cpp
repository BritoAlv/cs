// Problem: C. Dreaming of Freedom
// Contest: Codeforces - Codeforces Round 870 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1826/C
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
    int n, m;
    cin >> n >> m;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i <= m || (n / i) <= m)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (n == 1)
    {
        cout << "YES" << endl;
    }
    else if (n <= m && n > 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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
