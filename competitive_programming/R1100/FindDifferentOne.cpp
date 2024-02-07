// Problem: D. Find the Different Ones!
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int dp[n]; // dp[i] stores first index such that a[i] != a[index]. n if no exist.
    forn
    {
        if (i == 0 || a[i] != a[i - 1])
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (j == n)
                {
                    dp[i] = n;
                }
                else if (a[i] != a[j])
                {
                    dp[i] = j;
                    break;
                }
            }
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (dp[a] > b)
        {
            cout << -1 << wp << -1 << endl;
        }
        else
        {
            cout << a + 1 << wp << dp[a] + 1 << endl;
        }
        q--;
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
