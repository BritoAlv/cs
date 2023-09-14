// Problem: B. Permutation Sort
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1525/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: look at the borders, at most three op.
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    bool is_fine = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] < 0)
        {
            is_fine = false;
            break;
        }
    }
    if (is_fine)
    {
        cout << 0 << endl;
    }
    else if (a[0] == 1 || a[n - 1] == n)
    {
        cout << 1 << endl;
    }
    else if (a[0] == n && a[n - 1] == 1)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 2 << endl;
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
