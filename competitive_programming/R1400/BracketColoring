// Problem: D. Bracket Coloring
// Contest: Codeforces - Educational Codeforces Round 149 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1837/D
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
#define pb push_back
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    char a[n];
    forn
    {
        cin >> a[i];
    }
    int s[n];
    forn
    {
        s[i] = (a[i] == '(' ? 1 : -1) + (i == 0 ? 0 : s[i - 1]);
    }
    if (s[n - 1] != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> result(n);
        int ans = 1;
        int use_ = 1;
        forn
        {
            result[i] = use_;
            if (s[i] == 0 && i != n - 1)
            {
                if (s[i + 1] == s[0])
                {
                    use_ = 1;
                }
                else
                {
                    use_ = 2;
                    ans = 2;
                }
            }
        }
        cout << ans << endl;
        forn
        {
            cout << result[i] << wp;
        }
        cout << endl;
    }
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
