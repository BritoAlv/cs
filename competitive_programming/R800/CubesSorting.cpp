// Problem: A. Cubes Sorting
// Contest: Codeforces - Codeforces Round 672 (Div. 2)
// URL: https://codeforces.com/contest/1420/problem/A
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

void Solve()
{
    int n;
    cin >> n;
    int prev = 1e9 + 1;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        if (a[i] >= prev)
        {
            cout << "YES" << endl;
            return;
        }
        prev = a[i];
    }
    cout << "NO" << endl;
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
