// Problem: A. Ilya and a Colorful Walk
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/contest/1119/problem/A
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int dp[n];
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] != a[0])
        {
            dp[0] = i;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[n - 1])
        {
            dp[n - 1] = i;
            break;
        }
    }
    cout << max(dp[0], n - 1 - dp[n - 1]) << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
