// Problem: B. Make AP
// Contest: Codeforces - Codeforces Round 764 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1624/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: implementing it is the goal.
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
    int a, b, c;
    cin >> a >> b >> c;
    if ((b + (b - c)) % a == 0 && (b + (b - c)) > 0)
    {
        cout << "YES" << endl;
    }
    else if ((a + c) % (2 * b) == 0)
    {
        cout << "YES" << endl;
    }
    else if ((2 * b - a) % c == 0 && (b + (b - a)) > 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
