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

const ll mod = 998244353;

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

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    forn
    {
        cin >> a[i];
    }
    vl psums(n);
    psums[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        psums[i] = a[i] + psums[i - 1];
    }
    ll best = -1;
    ll c = 0;
    ll flag = 0;
    forn
    {
        best = max(best, abs(c + a[i]) + psums[n - 1] - psums[i]);
        c += a[i];
        flag |= c < 0;
    }
    if (!flag)
    {
        cout << f_pow(2, n) << endl;
        return;
    }
    ll ans = 0;
    c = 0;
    vi valids;
    forn
    {
        if (c + a[i] < 0 && abs(c + a[i]) + psums[n - 1] - psums[i] == best)
        {
            valids.pb(i);
        }
        c += a[i];
    }
    ll ap = 1;
    c = 0;
    int pt = 0;
    for (int i = 0; i < n && pt != sz(valids); i++)
    {
        c += a[i];
        if (i == valids[pt])
        {
            ans += ap * f_pow(2, n - 1 - i);
            ans %= mod;
            pt++;
        }
        else
        {
            if (c >= 0)
            {
                ap *= 2;
                ap %= mod;
            }
        }
    }

    cout << ans << endl;
    return;
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