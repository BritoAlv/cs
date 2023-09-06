// Problem: B. BAN BAN
// Contest: Codeforces - Codeforces Round 832 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1747/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: notice that a lower bound is ceil(n/2), now how
// obtain this ? , again not reading the subsequence lead me to
// WA, that means can't be found three indices i < j < k,
// such that B - A - N, a greedy algorithm is to place B's' at the
// end and 'N' at beginning.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    cout << n / 2 + n % 2 << '\n';
    for (int i = 0; i < n / 2; i++)
    {
        cout << 3 * i + 1 << ' ' << 3 * (n - i) << '\n';
    }
    if (n % 2 == 1)
    {
        cout << 3 * (n / 2) + 1 << ' ' << 3 * (n / 2 + 1) << '\n';
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