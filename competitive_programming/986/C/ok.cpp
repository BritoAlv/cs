#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

void solve()
{
    int n, m;
    ll v;
    cin >> n >> m >> v;
    vector<ll> arr(n);
    vector<int> p(n + 1, 0);
    vector<int> s(n + 1, 0);
    vector<ll> groups;
    ll c_sum = 0;
    forn
    {
        cin >> arr[i];
        c_sum += arr[i];
        if (c_sum >= v)
        {
            groups.push_back(c_sum);
            c_sum = 0;
        }
        p[i + 1] = groups.size();
    }
    c_sum = 0;
    groups = vector<ll>();
    for (int i = n - 1; i >= 0; i--)
    {
        c_sum += arr[i];
        if (c_sum >= v)
        {
            groups.push_back(c_sum);
            c_sum = 0;
        }
        s[i] = groups.size();
    }
    ll whole_sum = 0;
    vector<ll> p_sum(n + 1, 0);
    vector<ll> s_sum(n + 1, 0);
    forn
    {
        p_sum[i + 1] = p_sum[i] + arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        s_sum[i] = s_sum[i + 1] + arr[i];
    }
    whole_sum = s_sum[0];
    ll maxx = -1;
    set<pair<int, int>> S_INDEX;
    for (int i = 0; i <= n; i++)
    {
        S_INDEX.insert({s[i], -i});
    }
    for (int i = 0; i <= n; i++)
    {
        int fl = i;
        auto best = S_INDEX.lower_bound({(m - p[i]), -(1000000)});
        if (best != S_INDEX.end())
        {
            int fr = -(*best).second;
            ll apport = whole_sum - p_sum[fl] - s_sum[fr];
            if (maxx == -1 || maxx < apport)
                maxx = max(maxx, apport);
        }
    }
    cout << maxx << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}