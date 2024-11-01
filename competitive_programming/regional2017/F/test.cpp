#include <bits/stdc++.h>
using namespace std;

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back

const int maxn = 1e5 + 5;
const int maxt = (maxn << 2);

ll sgt[maxt];
#define mid ((l + r) >> 1)
#define left (i << 1)
#define right ((i << 1) | 1)

void update(int i, int l, int r, const int p, const ll v)
{
    if (l == r)
    {
        sgt[i] = max(v, sgt[i]);
        return;
    }
    if (p <= mid)
        update(left, l, mid, p, v);
    else
        update(right, mid + 1, r, p, v);

    sgt[i] = max(sgt[left], sgt[right]);
}

ll query(int i, int l, int r, int ql, int qr)
{
    if (l > r || l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
        return sgt[i];

    ll qal = query(left, l, mid, ql, qr), qar = query(right, mid + 1, r, ql, qr);

    return max(qal, qar);
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<ll> d(n);
    map<pair<int, int>, int> index;
    forn
    {
        cin >> x[i] >> y[i] >> d[i];
        pair<int, int> top = {x[i], y[i]};
        auto pt = index.find(top);
        if (pt == index.end())
        {
            index.emplace(top, i);
        }
        else
        {
            d[(*pt).second] += d[i];
            d[i] = 0;
        }
    }
    vector<pair<int, int>> Y(n);
    forn
    {
        Y[i] = {y[i], i};
    }
    sort(Y.begin(), Y.end());
    map<int, int> mapped_y;
    forn
    {
        if (mapped_y.find(Y[i].first) == mapped_y.end())
            mapped_y.emplace(Y[i].first, mapped_y.size());
    }
    int cy = mapped_y.size();
    vector<pair<pair<int, int>, int>> D(n);
    forn
    {
        D[i] = {{x[i], y[i]}, i};
    }
    ll ans = 0;
    sort(D.begin(), D.end());
    for (int i = 0; i < n; i++)
    {
        int cx = D[i].first.first;
        vector<pair<int, ll>> to_add;
        int j = i;
        while (j < n && D[j].first.first == cx)
        {
            int map_y = mapped_y[D[j].first.second];
            ll queryy = map_y == 0 ? 0 : query(1, 0, cy - 1, 0, map_y - 1);
            ll new_val = d[D[j].second] + queryy;
            ans = max(new_val, ans);
            to_add.push_back({map_y, new_val});
            j++;
        }
        i = j - 1;
        for (auto z : to_add)
        {
            update(1, 0, cy - 1, z.first, z.second);
        }
    }
    cout << ans << endl;
}