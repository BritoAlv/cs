// Problem: B. Diverse Substrings
// Contest: Codeforces - Codeforces Round 833 (Div. 2)
// URL: https://codeforces.com/contest/1748/problem/B
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
    vector<char> s(n);
    forn
    {
        cin >> s[i];
    }
    ull ans = 0;
    for (int l = 0; l < n; l++)
    {
        vector<int> count(10, 0);
        int n_distinct = 0;
        for (int r = l; r < min(n, l + 101); r++)
        {
            count[s[r] - '0']++;
            n_distinct += count[s[r] - '0'] == 1;
            int works = 1;
            for (int i = 0; i < 10; i++)
            {
                if (count[i] > n_distinct)
                {
                    works = 0;
                }
            }
            ans += works;
        }
    }
    cout << ans << endl;
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