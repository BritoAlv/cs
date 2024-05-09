// Problem: C. Even Number Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/C
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

vector<vector<vector<int>>> dp;

void init()
{
    int size = 100;
    dp = vector<vector<vector<int>>>();
    for (int i = 0; i <= size; i++)
    {
        vector<vector<int>> t;
        for (int j = 0; j <= size; j++)
        {
            t.pb(vector<int>(2));
        }
        dp.pb(t);
    }
    for (int j = 0; j <= size; j++)
    {
        dp[j][0][0] = 1;
        dp[j][0][1] = 0;
        dp[j][1][0] = (j % 2) == 1;
        dp[j][1][1] = 1;
    }
    for (int e = 0; e <= size; e++)
    {
        for (int o = 2; o <= size; o++)
        {
            for (int z = 0; z < 2; z++)
            {
                dp[e][o][z] = 0;
                if (e > 0)
                {
                    int result = (e < 2 || dp[e - 2][o][z]) && (dp[e - 1][o - 1][z]);
                    dp[e][o][z] = dp[e][o][z] || result;
                }
                if (o > 0)
                {

                    int result = (e == 0 || dp[e - 1][o - 1][!z]) && dp[e][o - 2][!z];
                    dp[e][o][z] = dp[e][o][z] || result;
                }
            }
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    int odd = 0;
    int even = 0;
    forn
    {
        int x;
        cin >> x;
        x = abs(x);
        odd += (x % 2);
        even += (x % 2) == 0;
    }
    cout << (dp[even][odd][0] ? "Alice" : "Bob") << endl;
    return;
}

int main()
{
    init();
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
