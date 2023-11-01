// Problem: B. Roof Construction
// Contest: Codeforces - Codeforces Round 769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/B
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
    int n;
    cin >> n;
    int lp2 = 1;
    while (true)
    {
        if (2 * lp2 > (n - 1))
        {
            break;
        }
        else
        {
            lp2 *= 2;
        }
    }
    for (int i = n - 1; i >= lp2; i--)
    {
        cout << i << wp;
    }
    cout << 0 << wp;
    for (int i = lp2 - 1; i >= 1; i--)
    {
        cout << i << wp;
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
