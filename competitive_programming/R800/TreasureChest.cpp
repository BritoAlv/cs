// Problem: A. Treasure Chest
// Contest: Codeforces - Educational Codeforces Round 157 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1895/problem/A
// Memory Limit: 512 MB
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
    int x, y, k;
    cin >> x >> y >> k;
    if (y <= x)
    {
        cout << y + (x - y) << endl;
    }
    else
    {
        // y > x
        cout << x + min(k, y - x) + 2 * (y - (x + min(k, y - x))) << endl;
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
