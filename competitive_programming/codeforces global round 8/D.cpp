// Problem: D. AND, OR and square sum
// Contest: Codeforces - Codeforces Global Round 8
// URL: https://codeforces.com/contest/1368/problem/D
// Memory Limit: 512 MB
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

int n;

void apply(int i, int j, long long a[], vector<vector<int>> &dp)
{
    long long one = a[i] & a[j];
    long long two = a[i] | a[j];
    a[i] = one;
    a[j] = two;
    for (int z = 0; z < 20; z++)
    {
        if (a[i] & (1 << z))
        {
            dp[z][i] = 1;
        }
        else
        {
            dp[z][i] = 0;
        }
        if (a[j] & (1 << z))
        {
            dp[z][j] = 1;
        }
        else
        {
            dp[z][j] = 0;
        }
    }
}

void Solve()
{
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(20, vector<int>(n, 0));
    forn
    {
        for (int j = 0; j < 20; j++)
        {
            if (a[i] & (1 << j))
            {
                dp[j][i] = 1;
            }
        }
    }
    for (int j = 19; j >= 0; j--)
    {
        vector<int> ones_pos;
        forn
        {
            if (dp[j][i] == 1)
            {
                ones_pos.pb(i);
            }
        }
        int pt = n - 1;
        for (int i = ones_pos.sz - 1; i >= 0; i--)
        {
            apply(ones_pos[i], pt--, a, dp);
        }
    }
    ull sum = 0;
    forn
    {
        sum += a[i] * a[i];
    }
    cout << sum << endl;
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
