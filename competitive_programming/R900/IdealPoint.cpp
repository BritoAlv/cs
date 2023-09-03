// Problem: B. Ideal Point
// Contest: Codeforces - Educational Codeforces Round 143 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1795/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    int k;
    cin >> n >> k;
    int max_left = 1;
    int min_right = 50;
    while (n > 0)
    {
        int l;
        int r;
        cin >> l >> r;
        if (l <= k && k <= r)
        {
            max_left = max(l, max_left);
            min_right = min(r, min_right);
        }
        n--;
    }

    cout << ((max_left == k && min_right == k) ? "YES" : "NO") << '\n';
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
