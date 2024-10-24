#include <bits/stdc++.h>


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

ll cost(int i, int j)
{
    return prefix_cost[i][0] + suffix_cost[j][n - 1] + suffix_cost[i][(j + i) / 2] + prefix_cost[j][(j + i) / 2 + 1];
}

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
    for (int k = 2; k < n; k++)
    {
        argmins[k][k] = k-1;
        dp[k][k] = dp[k-1][k - 1] + cost(k-1, k) - suffix_cost[k-1][n - 1] - prefix_cost[k-1][0];
    }
    for (int i = 2; i < n; i++)
    {
        for (int k = i - 1; k >= 2; k--)
        {
            ll mn = 1e18;
            for (int j = argmins[i - 1][k]; j <= min(i - 1, argmins[i][k + 1]); j++)
            {
                ll new_v = dp[j][k - 1] + cost(j, i) - suffix_cost[j][n - 1] - prefix_cost[j][0];
                if (mn > new_v)
                {
                    argmins[i][k] = j;
                    mn = new_v;
                }
            }
            dp[i][k] = mn;
        }
    }
    for (int k = 2; k < n; k++)
    {
        ll best = 1e18;
        for (int i = 0; i < n;i++)
        {
            best = min(best, dp[i][k]);
        }
        cout << (k + 1) * b + c * best << wp;
    }
}