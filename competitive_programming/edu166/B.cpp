// Problem: B. Increase/Decrease/Copy
// Contest: Codeforces - Educational Codeforces Round 166 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1976/problem/B
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n + 1];
    forn
    {
        cin >> a[i];
    }
    for (int i = 0; i < n + 1; i++)
    {
        cin >> b[i];
    }
    long long ans = 0;
    vector<pi> seg;
    forn
    {
        ans += abs(a[i] - b[i]);
        seg.pb({min(a[i], b[i]), max(a[i], b[i])});
    }
    ans += 1;
    long long best = 1e10;
    forn
    {
        if (b[n] >= seg[i].first && b[n] <= seg[i].second)
        {
            best = 0;
        }
        else if (b[n] >= seg[i].first)
        {
            best = min(best, (long long)b[n] - seg[i].second);
        }
        else
        {
            best = min(best, seg[i].first - (long long)b[n]);
        }
    }
    cout << ans + best << endl;
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
