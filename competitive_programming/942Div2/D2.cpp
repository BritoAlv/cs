// Problem: D2. Reverse Card (Hard Version)
// Contest: Codeforces - Codeforces Round 942 (Div. 2)
// URL: https://codeforces.com/contest/1972/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
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

int mcd(int a, int b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, a % b);
    }
}

void BruteSolve()
{
    int n, m;
    cin >> n >> m;
    ull ans = 0;
    for (int a1 = 1; a1 * a1 <= n; a1++)
    {
        for (int b1 = 1; b1 * b1 <= m; b1++)
        {
            if (mcd(a1, b1) == 1)
            {
                int max_ka = n / ((a1 + b1) * a1);
                int max_kb = m / ((a1 + b1) * b1);
                ans += min(max_ka, max_kb);
            }
        }
    }
    cout << ans << endl;
    return;
}

void Solve()
{
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
        BruteSolve();
    }
    return 0;
}