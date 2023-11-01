// Problem: A. Sorting with Twos
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/A
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
    forn
    {
        cin >> a[i];
    }
    for (int pow = 2; pow < 6; pow++)
    {
        for (int i = (1 << (pow - 1)); i < (1 << pow) - 1; i++)
        {
            if (i < (n - 1) && a[i] > a[i + 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
