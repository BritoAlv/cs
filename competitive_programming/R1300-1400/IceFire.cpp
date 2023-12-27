// Problem: C. Ice and Fire
// Contest: Codeforces - Polynomial Round 2022 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/problemset/problem/1774/C?locale=en
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

void Solve()
{
    int n;
    cin >> n;
    char S[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> S[i];
    }
    int dp[n - 1];
    dp[0] = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (S[i] == S[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    for (int x = 2; x <= n; x++)
    {
        cout << x - dp[x - 2] << wp;
    }
    cout << endl;
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