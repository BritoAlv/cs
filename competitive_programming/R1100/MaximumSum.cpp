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

const int mod = 1000000007;

long long max_sum_subarray(vector<int> &a)
{
    int n = a.size();
    long long psums[n];
    psums[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        psums[i] = a[i] + psums[i - 1];
    }
    vector<int> dp(n, 0);
    dp[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if ((psums[dp[i + 1]] - (psums[i])) >= 0)
        {
            dp[i] = dp[i + 1];
        }
        else
        {
            dp[i] = i;
        }
    }
    vector<long long> sums;
    forn
    {
        sums.pb(psums[dp[i]] - (i > 0 ? psums[i - 1] : 0));
    }
    sort(sums.begin(), sums.end());
    return max(0ll, sums[n - 1]) % mod;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn
    {
        cin >> a[i];
    }
    long long sum = 0;
    forn
    {
        sum += a[i];
    }
    sum %= mod;
    long long pow = 1;
    for (int i = 0; i < k; i++)
    {
        pow *= 2;
        pow %= mod;
    }
    pow--;
    pow *= max_sum_subarray(a);
    pow %= mod;
    sum += pow;
    sum %= mod;
    cout << (sum + mod) % mod << endl;
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