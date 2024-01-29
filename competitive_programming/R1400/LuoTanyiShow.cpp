// Problem: A. LuoTianyi and the Show
// Contest: Codeforces - Codeforces Round 872 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1824/A
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
    int n, m;
    cin >> n >> m;
    int l = 0;
    int r = 0;
    set<int> difs;
    forn
    {
        int a;
        cin >> a;
        if (a > 0)
        {
            difs.insert(a);
        }
        else if (a == -1)
        {
            l++;
        }
        else
        {
            r++;
        }
    }
    if (difs.size() == 0)
    {
        cout << min(m, max(l, r)) << endl;
        return;
    }
    vector<int> vv;
    for (auto x : difs)
    {
        vv.pb(x);
    }
    int sz = (int)vv.size();
    int ans = -1;
    for (int i = 0; i < sz; i++)
    {
        int this_l = min(vv[i] - 1, l + i);
        int this_r = min(m - vv[i], r + (sz - 1) - i);

        int new_ans = -1;
        if (l + i >= vv[i] - 1)
        {
            new_ans = max(new_ans, vv[i] + max(this_r, min(l + i + 1 - vv[i], m - vv[i])));
        }
        else
        {
            new_ans = max(new_ans, this_l + this_r + 1);
        }

        if (r + (sz - 1) - i >= m - vv[i])
        {
            new_ans = max(new_ans, m - vv[i] + 1 + max(this_l, min(r + (sz - 1) - i - m + vv[i], vv[i] - 1)));
        }
        else
        {
            new_ans = max(new_ans, this_l + this_r + 1);
        }
        ans = max(ans, new_ans);
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