// Problem: G1. Division + LCP (easy version)
// Contest: Codeforces - Codeforces Round 943 (Div. 3)
// URL: https://codeforces.com/contest/1968/problem/G1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
// je m appelle Alvaro j ai 21 ans.

using namespace std;

ll MOD = 998244353;

const ll N = 200000;
ll computed_pow[N] = {0};
ll computed_inv[N] = {0};

ll f_pow(ll base, ll exp)
{
    ll mod = MOD;
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

ll inv(ll num, ll mod)
{
    return f_pow(num, mod - 2);
}

void Solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<char> a(n);
    forn
    {
        cin >> a[i];
    }
    auto s = [&a](int len, int divisions) -> int {
        if (len == 0)
        {
            return 1;
        }
        if (len == 1)
        {
            int ans = 0;
            for (int i = 0; i < a.sz; i++)
            {
                ans += a[i] == a[0];
            }
            return ans >= divisions;
        }
        vl hh(a.sz, 0);
        for (int i = 0; i < a.sz; i++)
        {
            hh[i] = (a[i] - 'a' + 1) * computed_pow[i];
            hh[i] %= MOD;
            if (i > 0)
            {
                hh[i] += hh[i - 1];
                hh[i] %= MOD;
            }
        }
        queue<int> pos;
        ll fine = hh[len - 1];
        for (int i = 0; i <= a.sz - len; i++)
        {
            ll psum = (hh[i + len - 1] - (i > 0 ? hh[i - 1] : 0) + MOD);
            psum %= MOD;
            if (i > 0)
            {
                psum *= computed_inv[i];
                psum %= MOD;
            }
            if (psum == fine)
            {
                pos.push(i);
            }
        }
        vi g;
        g.pb(pos.front());
        pos.pop();
        while (pos.sz > 0)
        {
            if (pos.front() >= g.back() + len)
            {
                g.pb(pos.front());
            }
            pos.pop();
        }
        return g.sz >= divisions;
    };
    auto binary_search = [&n, &l, &s]() -> int {
        int st = 0;
        int ed = n / l;
        while (ed - st > 1)
        {
            int middle = st + (ed - st) / 2;
            if (s(middle, l))
            {
                st = middle;
            }
            else
            {
                ed = middle - 1;
            }
        }
        if (st + 1 <= ed && s(st + 1, l))
        {
            st++;
        }
        return st;
    };
    cout << binary_search() << endl;
    return;
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        computed_pow[i] = f_pow(45647, i);
        computed_inv[i] = inv(computed_pow[i], MOD);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    // int start = 0;
    while (test_cases-- > 0)
    {
        /*
        if(test_cases == -1)
        {
            // read and print the input;
            return;
        }
        */
        // cout << start++ << endl;
        Solve();
    }
    return 0;
}