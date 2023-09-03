// Problem: B. Indivisible
// Contest: Codeforces - Codeforces Round 869 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1818/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: notice that a working permutation for
// n = 6 is 2 1 4 3 6 5 and generalize it.

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
    }
    else if (n % 2 == 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            cout << i + 1 << ' ' << i << ' ';
        }
        cout << '\n';
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
}