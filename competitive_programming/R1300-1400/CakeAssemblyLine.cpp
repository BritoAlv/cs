// Problem: B. Cake Assembly Line
// Contest: Codeforces - Codeforces Round 850 (Div. 2, based on VK Cup 2022 - Final Round)
// URL: https://codeforces.com/problemset/problem/1786/B
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

int w, h;

void Solve()
{
    int n;
    cin >> n >> w >> h;
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    vector<pair<int, int>> segments;
    forn
    {
        long long e_start = b[i] + h - w - a[i];
        long long e_end = b[i] - h - a[i] + w;
        if (e_end < e_start)
        {
            cout << "NO" << endl;
            return;
        }
        segments.pb({e_start, e_end});
    }
    sort(segments.begin(), segments.end());
    if (segments[n - 1].first <= segments[0].second)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
