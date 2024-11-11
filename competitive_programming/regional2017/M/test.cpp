#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
using namespace std;

const ll MOD = 1e9 + 7;
const int maxn = 400005;
ll pows365[maxn];

struct suffix_array
{
    int n;
    vector<int> sa, lcp, rank;

    template <typename RAIter>
    suffix_array(const RAIter &bg, const RAIter &nd, int alp = 256) : n(nd - bg + 1), sa(n), lcp(n), rank(n)
    {
        vector<int> ws(max(n, alp));
        auto &x = lcp, &y = rank;
        copy(bg, nd, x.begin());
        iota(sa.begin(), sa.end(), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), alp = p)
        {
            p = j, iota(y.begin(), y.end(), n - j);
            fill(ws.begin(), ws.end(), 0);
            for (int i = 0; i < n; ws[x[i++]]++)
                if (sa[i] >= j)
                    y[p++] = sa[i] - j;
            partial_sum(ws.begin(), ws.end(), ws.begin());
            for (int i = n; i--;)
                sa[--ws[x[y[i]]]] = y[i];
            x.swap(y), p = 1, x[sa[0]] = 0;
            for (int i = 1, a, b; i < n; ++i)
                a = sa[i - 1], b = sa[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 0; i < n; ++i)
            rank[sa[i]] = i;
        for (int i = 0, j, k = lcp[0] = 0; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = sa[rank[i] - 1]; bg[i + k] == bg[j + k]; k++)
                ;
    }
};

map<pair<int, int>, int> O;
int sizes[maxn];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return O[a] < O[b];
};

int main()
{
    pows365[0] = 1;
    pows365[1] = 365;
    for (int j = 2; j < maxn; j++)
    {
        pows365[j] = (pows365[j - 1] * 365) % MOD;
    }
    int n;
    cin >> n;
    vector<int> Q;
    vector<vector<ll>> P(n);
    map<int, pair<int, int>> suffix_map;
    int lpt = 0;
    int pt3 = 0;
    forn
    {
        int k;
        cin >> k;
        lpt += k;
        sizes[i] = k;
        vector<int> vals;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            vals.push_back(x);
            Q.push_back(x);
            P[i].push_back(x);
            suffix_map[pt3] = {j, i};
            pt3++;
        }
        Q.push_back(301);
        pt3++;
    }
    suffix_array SA = suffix_array(Q.begin(), Q.end(), 320);
    for (int i = 0; i < SA.sa.size(); i++)
    {
        int suf = SA.sa[i];
        int value = i;
        if (suffix_map.find(suf) != suffix_map.end())
            O[suffix_map[suf]] = value;
        // need to get from suf to which suffix it corresponds.
    }
    set<pair<int, int>, decltype(cmp) *> current_min(cmp);
    forn
    {
        pair<int, int> A = {0, i};
        current_min.insert(A);
    }
    vector<int> ptss(n, 0);
    ll ans = 0;
    while (lpt > 0)
    {
        auto top = *current_min.begin();
        current_min.erase(top);
        int q = top.second;
        int t = P[q][ptss[q]];
        // cout << P[q][ptss[q]];
        ans += ((ll)P[q][ptss[q]] * pows365[lpt--]) % MOD;
        ptss[q]++;
        ans %= MOD;
        while (ptss[q] < P[q].size() && P[q][ptss[q]] < t)
        {
            // cout << P[q][ptss[q]];
            ans += ((ll)P[q][ptss[q]] * pows365[lpt--]) % MOD;
            ptss[q]++;
            ans %= MOD;
        }
        if (ptss[q] < P[q].size())
        {
            pair<int, int> A = {ptss[q], top.second};
            current_min.insert(A);
        }
    }
    // cout << endl;
    cout << ans << endl;
}