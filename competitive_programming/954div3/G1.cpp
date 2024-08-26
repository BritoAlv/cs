#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define even(x) ((x) % 2 == 0)
#define odd(x) ((x) % 2 == 1)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
#define print(x, name)                                                                                                 \
    cout << name << endl;                                                                                              \
    for (auto z : x)                                                                                                   \
        cout << z << wp;                                                                                               \
    cout << endl;
// je m appelle Alvaro j ai 21 ans.
int test_cases;
int test_cases_original;
#define t_number test_cases_original - test_cases

using namespace std;

vl vv(set<ll> &source, ll mul)
{
    vl res;
    ll cur = mul;
    while (cur <= *source.rbegin())
    {
        auto pt = source.lower_bound(cur);
        if (pt == source.end())
        {
            break;
        }
        if (*pt % mul == 0)
        {
            res.pb(*pt);
            cur = *pt + mul;
        }
        else
        {
            assert(*pt > cur);
            cur = *pt - (*pt % mul) + mul;
        }
    }
    return res;
}

void Solve()
{
    ll cut = 1000;
    ll n;
    cin >> n;
    vl a(n);
    set<pl> rems;
    map<ll, set<ll>> A;
    map<ll, set<ll>> B;
    map<pl, ll> counts;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        ll mc = __gcd(a[i], i + 1);
        pl pr = {(i + 1) / mc, a[i] / mc};
        if (pr.first < cut)
        {
            rems.insert(pr);
        }
        else
        {
            if (!exist(A, pr.first))
            {
                A[pr.first] = set<ll>();
            }
            A[pr.first].insert(pr.second);
        }
        if (!exist(B, pr.second))
        {
            B[pr.second] = set<ll>();
        }
        B[pr.second].insert(pr.first);

        if (!exist(counts, pr))
            counts[pr] = 0;
        counts[pr]++;
    }
    ll ans = 0;
    for (ll i = cut; i <= n; i++)
    {
        if (exist(A, i)) // iterate over all the indexes that are greater of equal than cut.
        {
            for (ll j = i; j <= n; j += i)
            {
                if (exist(B, j))
                {
                    for (auto x : B[j])
                    {
                        // mcd(x, j) = 1
                        // mcd(i, y) = 1
                        for (auto y : vv(A[i], x))
                        {
                            pl one = {i, y};
                            pl two = {x, j};
                            ans += counts[one] * counts[two];
                        }
                    }
                }
            }

            for (auto y : A[i])
            {
                B[y].erase(i);
            }
        }
    }
    vector<pl> remss;
    for (auto x : rems)
    {
        remss.pb(x);
    }
    /*
    For all pairs whose first index is less than cut.
    */
    for (int i = 0; i < sz(remss); i++)
    {
        for (int j = i + 1; j < sz(remss); j++)
        {
            if ((remss[j].second * remss[i].second) % (remss[j].first * remss[i].first) == 0)
            {
                ans += counts[remss[i]] * counts[remss[j]];
            }
        }
    }
    /*
    Two equal pairs may hold the condition.
    */
    for (auto x : counts)
    {
        if ((x.first.second * x.first.second) % (x.first.first * x.first.first) == 0)
            ans += ((x.second - 1) * x.second) / 2;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> test_cases_original;
    test_cases = test_cases_original;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}