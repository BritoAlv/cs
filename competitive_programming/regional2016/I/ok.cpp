#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

const int maxn = 6000;
ll prefix_cost[maxn][maxn];
ll suffix_cost[maxn][maxn];
ll dp[maxn][maxn];
int argmins[maxn][maxn];
ll n;

#define cost(i, j)                                                                                                     \
    (prefix_cost[i][0] + suffix_cost[j][n - 1] + suffix_cost[i][(j + i) / 2] + prefix_cost[j][(j + i) / 2 + 1])

int a = 0;

int get_arg_min(int low, int upper, int i, int k)
{
    a++;
    int result = -1;
    ll best = 1e18;
    for (int j = low; j <= min(upper, i - 1); j++)
    {
        ll candidate = dp[j][k - 1] + cost(j, i) - suffix_cost[j][n - 1] - prefix_cost[j][0];
        if (best > candidate || result == -1)
        {
            best = candidate;
            result = j;
        }
    }
    return result;
};

void solve2(int range_l, int range_u, int lb, int up, int k)
{
    if (range_l > range_u)
    {
        return;
    }
    argmins[range_l][k] = get_arg_min(lb, up, range_l, k);
    if (range_l == range_u)
    {
        return;
    }
    if (range_l + 1 == range_u)
    {
        argmins[range_u][k] = get_arg_min(argmins[range_l][k], up, range_u, k);
        return;
    }
    else
    {
        int next = (range_l + range_u) / 2;
        int new_low = argmins[range_l][k];
        argmins[next][k] = get_arg_min(new_low, up, next, k);
        solve2(range_l + 1, next - 1, new_low, argmins[next][k], k);
        solve2(next + 1, range_u, argmins[next][k], up, k);
    }
};

int main()
{
    ll b, c;
    cin >> n >> b >> c;
    vector<ll> h(n);
    forn
    {
        cin >> h[i];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 1e18;
            argmins[i][j] = -1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            prefix_cost[i][j] = (i - j) * h[j];
            if (j < i - 1)
            {
                prefix_cost[i][j] += prefix_cost[i][j + 1];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            suffix_cost[i][j] += (j - i) * h[j];
            if (j > i + 1)
            {
                suffix_cost[i][j] += suffix_cost[i][j - 1];
            }
        }
    }
    ll best = 1e18;
    forn
    {
        dp[i][0] = suffix_cost[i][n - 1] + prefix_cost[i][0];
        best = min(best, dp[i][0]);
    }
    cout << 1 * b + c * best << wp;
    best = 1e18;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            dp[i][1] = min(dp[i][1], cost(j, i));
        }
        best = min(best, dp[i][1]);
    }

    if (n == 1)
    {
        return 0;
    }
    cout << 2 * b + c * best << wp;

    for (int k = 2; k < n - 1; k++)
    {
        int low = k;
        int upper = n - 1;
        solve2(low, upper, 0, upper - 1, k);
        best = 1e18;
        for (int i = k; i < n; i++)
        {
            int j = argmins[i][k];
            dp[i][k] = dp[j][k - 1] + cost(j, i) - suffix_cost[j][n - 1] - prefix_cost[j][0];
            best = min(best, dp[i][k]);
        }
        cout << (k + 1) * b + c * best << wp;
    }
    cout << n * b << wp;
}