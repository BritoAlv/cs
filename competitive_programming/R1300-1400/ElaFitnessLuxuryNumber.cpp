// Problem: B. Ela's Fitness and the Luxury Number
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/problemset/problem/1737/B
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

long long solve2(long long r)
{
    long long x = (long long)sqrt(r);
    long long ans = 3 * (x);
    if ((x) * (x) + 2 * x > r)
    {
        ans -= 1;
    }
    if ((x) * (x) + x > r)
    {
        ans -= 1;
    }
    return ans;
}

void Solve()
{
    long long l, r;
    cin >> l >> r;
    cout << solve2(r) - (l == 1 ? 0 : solve2(l - 1)) << endl;
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
