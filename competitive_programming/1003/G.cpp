// Problem: G. Skibidus and Capping
// Contest: Codeforces - Codeforces Round 1003 (Div. 4)
// URL: https://codeforces.com/problemset/problem/2065/G
// Memory Limit: 256 MB
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

const int N = 3 * 100000 + 1;
int primes[N];

void init()
{
    fori(0, N - 1) primes[i] = i;
    fori(2, N - 1)
    {
        if (primes[i] == i)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                if (primes[j] == j)
                    primes[j] = i;
            }
        }
    }
}

ll c2(ll g)
{
    return (g * (g - 1)) / 2;
}

int is_prime(int x)
{
    return primes[x] == x;
}

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    ll ones = 0;
    map<int, vi> only_prime;
    map<pi, vi> prod_prime;
    ll only_prime_size = 0;
    ll prod_prime_size = 0;
    fori(0, n - 1)
    {
        if (a[i] == 1)
            ones++;
        else if (is_prime(a[i]) && a[i] > 1)
        {
            if (!only_prime.count(a[i]))
            {
                only_prime[a[i]] = vi();
            }
            only_prime[a[i]].push_back(i);
            only_prime_size++;
        }
        else
        {
            int sm = a[i] / primes[a[i]];
            if (is_prime(sm))
            {
                pi cur = {min(sm, primes[a[i]]), max(sm, primes[a[i]])};
                if (!prod_prime.count(cur))
                {
                    prod_prime[cur] = vi();
                }
                prod_prime[cur].pb(i);
                prod_prime_size++;
            }
        }
    }
    ll ans = 0;
    ll sum = 0;
    for (auto z : only_prime)
    {
        sum += (ll)z.second.size() * (only_prime_size - (ll)z.second.size());
    }
    sum /= 2;
    ans += sum;
    for (auto z : prod_prime)
    {
        ll total = z.second.size();
        ans += c2(total) + total;
        int p1 = z.first.first;
        int p2 = z.first.second;
        if (only_prime.count(p1))
        {
            ans += total * (ll)only_prime[p1].size();
        }
        if (only_prime.count(p2) && p2 != p1)
        {
            ans += total * (ll)only_prime[p2].size();
        }
    }
    ans += prod_prime_size * ones;
    cout << ans << endl;
}

int main()
{
    init();
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}