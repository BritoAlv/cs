#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int validator(int mask, int n, int k)
{
    int money = 0;
    forn
    {
        if (!((mask & (1 << i)) > 0))
        {
            money++;
        }
        else if (money >= k)
        {
            money -= k;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> cost(n);
    forn
    {
        cin >> cost[i];
    }
    ll ans = 1e18;
    for (int t = 0; t < (1 << n); t++)
    {
        ll total_money = 0;
        if (validator(t, n, k))
        {
            for (int j = 0; j < n; j++)
            {
                if (!((t & (1 << j)) > 0))
                {
                    total_money += cost[j];
                }
            }
            ans = min(total_money, ans);
        }
    }
    cout << ans << endl;
}