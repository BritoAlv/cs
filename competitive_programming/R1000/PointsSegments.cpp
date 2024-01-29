// Problem: A. Points in Segments
// Contest: Codeforces - Codeforces Round 501 (Div. 3)
// URL: https://codeforces.com/contest/1015/problem/A
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
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> seg;
    vector<pair<int, int>> segg;
    forn
    {
        int a, b;
        cin >> a >> b;
        segg.pb({a, b});
    }
    sort(segg.begin(), segg.end());
    for (auto x : segg)
    {
        if (seg.size() == 0 || x.second > (*seg.rbegin()).second)
        {
            seg.insert(x);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++)
    {
        int found = 0;
        pair<int, int> to_find = {i, 101};
        auto to_findd = seg.lower_bound(to_find);
        if (to_findd != seg.begin())
        {
            to_findd--;
            int first = (*to_findd).first;
            int second = (*to_findd).second;
            if (i >= first && i <= second)
            {
                found = 1;
            }
        }
        if (!found)
        {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << wp;
    }
    cout << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
