// Problem: B. Monsters Attack!
// Contest: Codeforces - Educational Codeforces Round 162 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1923/problem/B
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    ull n, k;
    cin >> n >> k;
    vector<pi> m(n);
    forn
    {
        cin >> m[i].second;
    }
    forn
    {
        cin >> m[i].first;
        m[i].first = abs(m[i].first);
    }
    vector<ull> ps(n, 0);
    forn
    {
        ps[m[i].first - 1] += m[i].second;
    }
    for (int i = 1; i < n; i++)
    {
        ps[i] += ps[i - 1];
    }
    forn
    {
        if (ps[i] > k * (i + 1))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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