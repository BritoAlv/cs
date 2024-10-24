#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define pi pair<int, int>
using namespace std;

ll mod = 1e9 + 7;
const int maxn = 1001;

ll factorials[maxn];
ll inverse[maxn];

ll f_pow(ll base, ll exp, ll mod)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % mod;
    ll middle = f_pow(base, exp / 2, mod);
    middle *= middle;
    middle %= mod;
    if (exp % 2)
    {
        middle *= base;
        middle %= mod;
    }
    return middle;
}

ll inv(ll base, ll mod)
{
    return f_pow(base, mod - 2, mod);
}

ll comb(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    ll result = factorials[n];
    result *= inverse[k];
    result %= mod;
    result *= inverse[n - k];
    result %= mod;
    return result;
}

void init()
{
    factorials[0] = 1;
    inverse[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        factorials[i] = factorials[i - 1] * i;
        factorials[i] %= mod;
        inverse[i] = inv(factorials[i], mod);
    }
}

int main()
{
    init();
    int n;
    cin >> n;
    vector<pi> P(n);
    map<pi, int> one;
    map<pi, int> two;
    forn
    {
        cin >> P[i].first >> P[i].second;
        one[{2 * P[i].first, 2 * P[i].second}]++;
    }
    forn
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = P[i].first + P[j].first;
            int y = P[i].second + P[j].second;
            two[{x, y}]++;
        }
    }
    map<pair<int, int>, ll> R;
    auto query = [&R](int n, int k) -> ll {
        if (R.find({n, k}) != R.end())
        {
            return R[{n, k}];
        }
        return R[{n, k}] = comb(n, k);
    };
    map<int, int> two_center_count;
    map<int, int> one_center_count;
    for (auto c : two)
    {
        two_center_count[c.second]++;
    }
    for (auto c : one)
    {
        one_center_count[c.second]++;
    }
    vector<ll> result(n + 1, 0);
    result[1] = n;
    for (int s = 2; s <= n; s ++) // O(1000)
    {
        // if even, for every center count C(cant, s)
        // if odd, for every center count  C(cant, s-1), then multiyply by center count.
        if (s % 2 == 0)
        {
            for (auto c : two_center_count)
            {
                ll contribute = c.second;
                contribute *= query(c.first, s / 2);
                contribute %= mod;
                result[s] += contribute;
                result[s] %= mod;
            }
        }
        else
        {
            for (auto c : one)
            {
                ll contrib = c.second;
                contrib *= comb(two[c.first], (s - 1) / 2);
                contrib %= mod;
                result[s] += contrib;
                result[s] %= mod;
            }
        }
    }
    for (int s = 1; s <= n; s++)
    {
        cout << result[s] << wp;
    }
    cout << endl;
}