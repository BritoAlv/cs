#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

const ll INF = LONG_LONG_MAX;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<pair<ll, ll>> b(m);
    vector<pair<ll, int>> k;
    forn
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    forn
    {
        a[i] += (i > 0 ? a[i - 1] : 0);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i].first;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i].second;
        k.pb({b[i].second / b[i].first, i});
    }
    sort(k.begin(), k.end());

    ll ans = INF;
    int pt = -1;
    ll right_apport = 0;
    ll left_c_apport = 0;
    for (int i = 0; i < m; i++)
    {
        right_apport += b[i].first;
    }
    for (int sz = 0; sz <= n; sz++)
    {
        while (pt + 1 < m && k[pt + 1].first < sz)
        {
            right_apport -= b[k[pt + 1].second].first;
            left_c_apport += b[k[pt + 1].second].second;
            pt++;
        }
        ll left_aport = (sz < n) ? a[n - 1 - sz] : 0;
        //cout << left_aport << wp << right_apport << endl;
        ans = min(ans, left_aport + (sz) * right_apport + left_c_apport);
    }
    cout << ans << endl;
}