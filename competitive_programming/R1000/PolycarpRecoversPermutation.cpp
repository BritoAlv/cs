// Problem: C. Polycarp Recovers the Permutation
// Contest: Codeforces - Codeforces Round 756 (Div. 3)
// URL: https://codeforces.com/contest/1611/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int n_index = -1;
    forn
    {
        cin >> a[i];
        if (a[i] == n)
        {
            n_index = i;
        }
    }
    if (n_index == 0 || n_index == n - 1)
    {
        if (n_index == 0)
        {
            cout << n << wp;
            for (int i = n - 1; i >= 1; i--)
            {
                cout << a[i] << wp;
            }
            cout << endl;
        }
        else
        {
            for (int i = n - 2; i >= 0; i--)
            {
                cout << a[i] << wp;
            }
            cout << n << endl;
        }
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
