// Problem: D. Jellyfish and Mex
// Contest: Codeforces - Codeforces Round 901 (Div. 2)
// URL: https://codeforces.com/contest/1875/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    map<int, int> info;
    forn
    {
        int t;
        cin >> t;
        if (info.find(t) == info.end())
        {
            info[t] = 0;
        }
        info[t]++;
    }
    int start_mex = 0;
    for (auto x : info)
    {
        if (x.first != start_mex)
        {
            break;
        }
        start_mex++;
    }
    if (start_mex == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<vector<int>> dp;
        for (int i = 0; i < start_mex; i++)
        {
            vector<int> row(start_mex, 0);
            dp.push_back(row);
        }

        for (int x = 0; x < start_mex; x++)
        {
            for (int mex = 1; mex <= start_mex; mex++)
            {
                dp[mex - 1][x] = (x == 0 ? (info[x] - 1) * (mex)
                                         : min((info[x] - 1) * (mex) + x + dp[x - 1][x - 1], dp[mex - 1][x - 1]));
            }
        }
        cout << dp[start_mex - 1][start_mex - 1] << endl;
    }
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
