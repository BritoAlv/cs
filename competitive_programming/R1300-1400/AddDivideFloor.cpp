// Problem: C. Add, Divide and Floor
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1901/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int minn = 1e9 + 1;
    int maxx = -1;
    forn
    {
        int a;
        cin >> a;
        minn = min(a, minn);
        maxx = max(a, maxx);
    }
    vector<int> ops;
    while (minn != maxx)
    {
        if (minn % 2 == 0)
        {
            minn = minn / 2;
            maxx = maxx / 2;
            ops.pb(0);
        }
        else
        {
            minn = (minn + 1) / 2;
            maxx = (maxx + 1) / 2;
            ops.pb(1);
        }
    }
    cout << ops.size() << endl;
    if (ops.size() <= n && ops.size() > 0)
    {
        for (auto x : ops)
        {
            cout << x << wp;
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
