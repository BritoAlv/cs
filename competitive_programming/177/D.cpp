// Problem: D. Even String
// Contest: Codeforces - Educational Codeforces Round 177 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2086/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// You might break and that's okay.
// Tags:
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

const ll MOD = 998244353;
const int N = 5 * 100001;

ll factorials[N];
ll inverses[N];

ll f_pow(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % MOD;
    ll middle = f_pow(base, exp / 2);
    middle *= middle;
    middle %= MOD;
    if (exp % 2)
    {
        middle *= base;
        middle %= MOD;
    }
    return middle;
}

ll inverse(ll number)
{
    // a * a^{x-2} = a^{x-1} = 1 mod p
    return f_pow(number, MOD - 2);
}

ll comb(ll a, ll b)
{
    ll ans = factorials[a];
    ans *= inverses[b];
    ans %= MOD;
    ans *= inverses[a - b];
    ans %= MOD;
    return ans;
}

ll mix(ll a, ll b)
{
    return comb(a + b, b);
}

void mod(ll &a)
{
    a = a % MOD;
}

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

void Solve()
{
    int n = 26;
    ll sum = 0;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    vl c;
    fori(0, n - 1) if (a[i] > 0) c.pb(a[i]);
    a = c;
    n = a.size();
    vl p(n);
    fori(0, n - 1)
    {
        sum += a[i];
        p[i] = sum;
    }
    vector<vl> dp(n, vl(sum + 1, 0));
    fori(0, n - 1)
    {
        if (i == 0)
        {
            dp[i][0] = 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][0] * mix(p[i - 1], a[i]);
            mod(dp[i][0]);
        }
        for (int n_evens = 1; n_evens <= sum; n_evens++)
        {
            if (i > 0)
            {
                if (n_evens >= a[i])
                {
                    ll comb2 = dp[i - 1][n_evens - a[i]] * mix(n_evens - a[i], a[i]);
                    mod(comb2);
                    dp[i][n_evens] += comb2;
                    mod(dp[i][n_evens]);
                }
                if (p[i - 1] >= n_evens)
                {
                    ll comb2 = dp[i - 1][n_evens] * mix(p[i - 1] - n_evens, a[i]);
                    mod(comb2);
                    dp[i][n_evens] += comb2;
                    mod(dp[i][n_evens]);
                }
            }
            else
            {
                dp[i][n_evens] = (a[i] == n_evens);
            }
        }
    }
    // fori(0, n - 1) print(dp[i]);
    ll sum_to = (sum / 2 + sum % 2);
    cout << dp[n - 1][sum_to] << endl;
}

int main()
{
    factorials[0] = 1;
    factorials[1] = 1;
    fori(2, N - 1)
    {
        factorials[i] = i * factorials[i - 1];
        factorials[i] %= MOD;
    }
    inverses[0] = 1;
    inverses[1] = 1;
    fori(2, N - 1)
    {
        inverses[i] = inverse(factorials[i]);
    }
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}