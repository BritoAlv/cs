// Problem: C. Did We Get Everything Covered?
// Contest: Codeforces - Codeforces Round 921 (Div. 2)
// URL: https://codeforces.com/contest/1925/problem/C
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
#define pb push_back
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n, k, lens;
    cin >> n >> k >> lens;
    vector<char> s(lens);
    for (int i = 0; i < lens; i++)
    {
        cin >> s[i];
    }
    int dp[k + 1][n + 1];
    map<char, set<int>> app;
    for (int i = 0; i < k; i++)
    {
        app[(char)('a' + i)] = set<int>();
    }
    for (int i = 0; i < lens; i++)
    {
        app[s[i]].insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = lens;
    }
    vector<char> minimals(n + 1);
    for (int i = 1; i <= k; i++)
    {
        if (app[(char)('a' + (i - 1))].size() == 0)
        {
            cout << "NO" << endl;
            for (int h = 0; h < n; h++)
            {
                cout << (char)('a' + (i - 1));
            }
            cout << endl;
            return;
        }
        dp[i][1] = *(app[(char)('a' + (i - 1))].rbegin());
        if (dp[0][1] > dp[i][1])
        {
            dp[0][1] = min(dp[i][1], dp[0][1]);
            minimals[1] = (char)('a' + (i - 1));
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < k; i++)
        {
            char letter = 'a' + i;
            int minn = dp[0][len - 1];
            auto it = app[letter].lower_bound(minn);
            if (it == app[letter].begin())
            {
                cout << "NO" << endl;
                // this means that starting with letter and this len there is a subsequence that do not appear.
                // but recall that all the previous one appear.
                string tt = "";
                tt += letter;
                for (int j = len - 1; j >= 1; j--)
                {
                    tt += minimals[j];
                }
                for (int i = len + 1; i <= n; i++)
                {
                    tt += "a";
                }
                cout << tt << endl;
                return;
            }
            else
            {
                it--;
                dp[i + 1][len] = *(it);
                if (dp[0][len] > dp[i + 1][len])
                {
                    dp[0][len] = min(dp[0][len], dp[i + 1][len]);
                    minimals[len] = letter;
                }
            }
        }
    }
    cout << "YES" << endl;
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