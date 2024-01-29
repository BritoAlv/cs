// Problem: E. Vlad and a Pair of Numbers
// Contest: Codeforces - Codeforces Round 847 (Div. 3)
// URL: https://codeforces.com/contest/1790/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    ull x;
    cin >> x;
    if (x % 2 == 1)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 30; i >= 1; i--)
    {
        if (x & (1 << i) && x & (1 << (i - 1)))
        {
            cout << "-1" << endl;
            return;
        }
    }
    cout << x - x / 2 << wp << x + x / 2 << endl;
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
