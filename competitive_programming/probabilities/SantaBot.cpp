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

ll mod = 998244353;

ll f_pow(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % mod;
    ll middle = f_pow(base, exp / 2);
    middle *= middle;
    middle %= mod;
    if (exp % 2)
    {
        middle *= base;
        middle %= mod;
    }
    return middle;
}

ll inverse(ll number)
{
    // a * a^{x-2} = a^{x-1} = 1 mod p
    return f_pow(number, mod - 2);
}

void Solve()
{
    ll n;
    cin >> n;
    map<int, ll> c;
    vi count(n, 0);
    vector<vector<int>> likes(n, vector<int>());
    forn
    {
        int k;
        cin >> k;
        count[i] = k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            likes[i].pb(x);
            if (!exist(c, x))
                c[x] = 0;
            c[x]++;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        pi frac2 = {0, count[i]};
        for (auto x : likes[i])
        {
            frac2.first += c[x];
        }
        ll num = frac2.first;
        ll den = frac2.second;
        ll gcd = __gcd(num, den);
        num /= gcd;
        den /= gcd;
        sum += ((num * inverse(den)) % mod);
        sum %= mod;
    }
    ll y = inverse((n * n) % mod);
    ll x = sum;
    ll ans = (x * y) % mod;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}