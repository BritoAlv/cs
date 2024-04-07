// Problem: C. Left and Right Houses
// Contest: Codeforces - Codeforces Round 935 (Div. 3)
// URL: https://codeforces.com/contest/1945/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<char> a(n);
    int ones = 0;
    forn
    {
        cin >> a[i];
        ones += a[i] == '1';
    }
    vector<pi> ans(n + 1);
    ans[0] = {0, ones};
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] == '1')
        {
            ans[i] = {ans[i - 1].first, ans[i - 1].second - 1};
        }
        else
        {
            ans[i] = {ans[i - 1].first + 1, ans[i - 1].second};
        }
    }
    vector<pi> valids;
    for (int i = 0; i <= n; i++)
    {
        if (ans[i].first >= (i / 2 + i % 2) && ans[i].second >= ((n - i) / 2 + (n - i) % 2))
        {
            if (i < n / 2)
            {
                valids.pb({(n + 1) / 2 - i, i});
            }
            else
            {
                valids.pb({i - n / 2, i});
            }
        }
    }
    sort(valids.begin(), valids.end());
    cout << valids[0].second << endl;
    return;
}

int main()
{
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
