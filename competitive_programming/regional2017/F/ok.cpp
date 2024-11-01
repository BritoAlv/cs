#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> d(n);
    forn
    {
        cin >> x[i] >> y[i] >> d[i];
    }
    ll ans = 0;
    for (int t = 0; t < (1 << n); t++)
    {
        ll sum = 0;
        vector<pair<ll, ll>> xs;
        int flag = 1;
        forn
        {
            int on = t & (1 << i);
            if (on)
            {
                sum += d[i];
                xs.push_back({x[i], y[i]});
            }
        }
        sort(xs.begin(), xs.end());
        for (int h = 1; h < xs.size(); h++)
        {
            if(xs[h].first <= xs[h-1].first)
            {
                flag = 0;
            }
            if(xs[h].second <= xs[h-1].second)
            {
                flag = 0;
            }
        }
        if(flag)
        {
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}