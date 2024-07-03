// Problem: B. Collatz Conjecture
// Contest: Codeforces - Codeforces Round 955 (Div. 2, with prizes from NEAR!)
// URL: https://codeforces.com/contest/1982/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0)
    {
        int copy = x;
        int rem = min(k, (y - x % y));
        x += rem;
        k -= rem;
        while (x % y == 0)
        {
            x /= y;
        }
        if (copy == x)
        {
            k -= (k / rem) * rem;
        }
    }
    cout << x << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
