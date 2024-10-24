#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> costs(n, 0);
    ll sum = 0;
    forn
    {
        cin >> costs[i];
        sum += costs[i];
    }
    int pt = 0;
    ll ans = 0;
    set<pair<ll, int>> maxs;
    for (int i = k; i < n; i++)
    {
        if(pt == 0)
        {
            maxs.insert({costs[i], i});
        }
        else
        {
            auto smaller = *maxs.begin();
            if (smaller.first < costs[i])
            {
                maxs.erase(smaller);
                maxs.insert({costs[i], i});
            }
        }
        pt++;
        if(pt == k+1)
        {
            pt = 0;
        }
    }
    for(auto m : maxs)
    {
        ans += m.first;
        //cout << m.first << wp;
    }
    cout << sum - ans << endl;
}