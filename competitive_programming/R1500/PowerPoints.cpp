// Problem: E. Power of Points
// Contest: Codeforces - Codeforces Round 891 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1857/E
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
    vector<pair<ull, int>> a(n);
    forn
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ull psums[n];
    psums[0] = a[0].first;
    for (int i = 1; i < n; i++)
    {
        psums[i] = psums[i - 1] + a[i].first;
    }
    ull ssums[n];
    ssums[n - 1] = a[n - 1].first;
    for (int i = n - 2; i >= 0; i--)
    {
        ssums[i] = ssums[i + 1] + a[i].first;
    }
    ull ans[n];
    forn
    {
        // j >= i
        // j <  i
        ans[a[i].second] = ssums[i] + (n - 1 - i + 1) - a[i].first * (n - i);
        if (i > 0)
        {
            ans[a[i].second] += a[i].first * (i - 1 - 0 + 1) + (i - 1 - 0 + 1) - psums[i - 1];
        }
    }
    forn
    {
        cout << ans[i] << wp;
    }
    cout << endl;
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
