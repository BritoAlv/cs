// Problem: D1. Reverse Card (Easy Version)
// Contest: Codeforces - Codeforces Round 942 (Div. 2)
// URL: https://codeforces.com/contest/1972/problem/D1
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

ull lk(ull n, ull m)
{
    return (n + m) / (m * m);
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    ull ans = 0;
    for (int j = 1; j <= 1; j++)
    {
        int k = 1;
        while (true)
        {
            ull number = k * j;
            number *= j;
            number -= j;
            if (number <= n && number >= 1)
            {
                ans++;
            }
            else if (number > n)
            {
                break;
            }
            k++;
        }
    }
    for (ull j = 2; j <= m; j++)
    {
        ans += lk(n, j);
    }
    cout << ans << endl;
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
