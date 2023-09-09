// Problem: B. Promo
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1697/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: use suffix sums, got wa due to not calculating well index
// of sums
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void Solve()
{
    int n, q;
    cin >> n >> q;
    int pr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i];
    }
    long long sum[n];
    sort(pr, pr + n);
    sum[n - 1] = pr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sum[i] = pr[i] + sum[i + 1];
    }
    while (q > 0)
    {
        int x;
        int y;
        cin >> x >> y;
        cout << sum[n - x] - (x == y ? 0 : sum[n - x + y]) << '\n';
        q--;
    }
    return;
}
int main()
{
    Solve();
    return 0;
}
