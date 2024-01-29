// Problem: C. Bricks and Bags
// Contest: Codeforces - Codeforces Round 831 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1740/C
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
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<long long> results;
    long long middle;
    long long left;
    if (1)
    {
        middle = a[0];
        left = a[n - 1];
        vector<pair<long long, int>> rems;
        for (int i = 1; i < n - 1; i++)
        {
            rems.pb({abs(a[i] - middle), i});
        }
        sort(rems.begin(), rems.end());
        long long actual = abs(middle - left) + abs(middle - a[rems[0].second]);
        for (int i = 0; i < rems.size() - 1; i++)
        {
            actual = max(actual, abs(a[rems[i].second] - left) + abs(a[rems[i].second] - a[rems[i + 1].second]));
        }
        results.pb(actual);
    }
    if (1)
    {
        middle = a[n - 1];
        left = a[0];
        vector<pair<long long, int>> rems;
        for (int i = 1; i < n - 1; i++)
        {
            rems.pb({abs(a[i] - middle), i});
        }
        sort(rems.begin(), rems.end());
        long long actual = abs(middle - left) + abs(middle - a[rems[0].second]);
        for (int i = 0; i < rems.size() - 1; i++)
        {
            actual = max(actual, abs(a[rems[i].second] - left) + abs(a[rems[i].second] - a[rems[i + 1].second]));
        }
        results.pb(actual);
    }
    cout << max(results[0], results[1]) << endl;
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