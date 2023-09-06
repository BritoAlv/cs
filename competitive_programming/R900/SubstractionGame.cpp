// Problem: A. Subtraction Game
// Contest: Codeforces - Codeforces Round 884 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1844/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: a+b is invariant

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int a;
    int b;
    cin >> a >> b;
    if (a > 1)
    {
        cout << 2 * (a + b) + 1 << '\n';
    }
    else
    {
        cout << (b + 1) << '\n';
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
