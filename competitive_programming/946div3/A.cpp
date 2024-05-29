// Problem: A. Phone Desktop
// Contest: Codeforces - Codeforces Round 946 (Div. 3)
// URL: https://codeforces.com/contest/1974/problem/A
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

int ceil(int n, int k)
{
    return n / k + (n % k) != 0;
}

void Solve()
{
    int one, two;
    cin >> one >> two;
    int ans = 0;
    while (two || one > 0)
    {
        if (two >= 2)
        {
            ans += 1;
            two -= 2;
            one = max(0, one - 7);
        }
        else if (two == 1)
        {
            ans += 1;
            two -= 1;
            one = max(0, one - 11);
        }
        else
        {
            ans += 1;
            one = max(0, one - 15);
        }
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
