// Problem: F. Yet Another Problem About Pairs Satisfying an Inequality
// Contest: Codeforces - Codeforces Round 806 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1703/F
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
    int n;
    cin >> n;
    int a[n];
    int mark[n];
    int p_sum[n];
    forn
    {
        cin >> a[i];
        mark[i] = a[i] < i + 1;
        p_sum[i] = mark[i] + (i > 0 ? p_sum[i - 1] : 0);
    }
    long long ans = 0;
    forn
    {
        if (mark[i] && a[i] > 1)
        {
            ans += p_sum[a[i] - 2];
        }
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
