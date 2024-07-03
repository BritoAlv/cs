// Problem: C. Boring Day
// Contest: Codeforces - Codeforces Round 955 (Div. 2, with prizes from NEAR!)
// URL: https://codeforces.com/contest/1982/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    forn
    {
        cin >> a[i];
    }
    vector<long long> psums(n);
    forn
    {
        psums[i] = a[i];
        if (i > 0)
            psums[i] += psums[i - 1];
    }
    vector<int> dp(n, 0);
    dp[n - 1] = (a[n - 1] >= l && a[n - 1] <= r);
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        int st = i;
        int ed = n - 1;
        if (psums[ed] - (i > 0 ? psums[i - 1] : 0) >= l)
        {
            while (ed - st > 1)
            {
                int middle = st + (ed - st) / 2;
                long long sum = psums[middle] - (i > 0 ? psums[i - 1] : 0);
                if (sum >= l)
                {
                    ed = middle;
                }
                else
                {
                    st = middle + 1;
                }
            }
            if (ed - 1 >= st && psums[ed - 1] - (i > 0 ? psums[i - 1] : 0) >= l)
            {
                ed--;
            }
            long long sum = psums[ed] - (i > 0 ? psums[i - 1] : 0);
            if (sum <= r)
                dp[i] = max(dp[i], 1 + (ed + 1 == n ? 0 : dp[ed + 1]));
        }
    }

    cout << dp[0] << endl;
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
