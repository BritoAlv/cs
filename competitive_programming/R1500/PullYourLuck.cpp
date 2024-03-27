// Problem: C. Pull Your Luck
// Contest: Codeforces - Nebius Welcome Round (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1804/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, x, p;
    cin >> n >> x >> p;
    ull actual = x;
    for (int r = 1; r <= 2 * n; r++)
    {
        if (r > p)
        {
            break;
        }
        actual += r;
        actual %= n;
        if (actual == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
