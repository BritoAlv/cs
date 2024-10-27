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
