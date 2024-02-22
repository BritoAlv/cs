// Problem: A. Recovering a Small String
// Contest: Codeforces - Codeforces Round 925 (Div. 3)
// URL: https://codeforces.com/contest/1931/problem/A
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<string> valids;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            for (int l = 0; l < 26; l++)
            {
                if (i + j + l == n - 3)
                {
                    string r = "";
                    r += (char)('a' + i);
                    r += (char)('a' + j);
                    r += (char)('a' + l);
                    valids.pb(r);
                }
            }
        }
    }
    sort(valids.begin(), valids.end());
    cout << valids[0] << endl;
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
