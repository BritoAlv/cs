// Problem: F. Vasilije Loves Number Theory
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/contest/1878/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (long long i = 0; i < n; i++)
using namespace std;

bool is_prime[1001];

vector<long long> primes;

void init()
{
    for (long long i = 0; i < 1001; i++)
    {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    for (long long i = 2; i < 1001; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (long long j = 2 * i; j < 1001; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

unordered_map<long long, long long> mix(unordered_map<long long, long long> &A, unordered_map<long long, long long> &B)
{
    unordered_map<long long, long long> result;
    for (auto x : A)
    {
        if (result.find(x.first) == result.end())
        {
            result[x.first] = 0;
        }
        result[x.first] += x.second;
    }
    for (auto x : B)
    {
        if (result.find(x.first) == result.end())
        {
            result[x.first] = 0;
        }
        result[x.first] += x.second;
    }
    return result;
}

bool dividess(unordered_map<long long, long long> &A, unordered_map<long long, long long> &B)
{
    for (auto x : B)
    {
        if (x.second > A[x.first])
        {
            return false;
        }
    }
    return true;
}

unordered_map<long long, long long> get_exps(long long n)
{
    unordered_map<long long, long long> exps;
    long long final_n = 1;
    for (auto x : primes)
    {
        long long exp = 0;
        long long temp = n;
        while (temp % x == 0)
        {
            exp++;
            temp = temp / x;
            final_n *= x;
        }
        exps[x] = exp;
    }
    if (n / final_n != 1)
    {
        exps[n / final_n] = 1;
    }
    return exps;
}

long long get_divisors(unordered_map<long long, long long> exps)
{
    long long result = 1;
    for (auto x : exps)
    {
        result *= (x.second + 1);
    }
    return result;
}

long long test_cases;

void Solve()
{
    long long n, q;
    cin >> n >> q;
    unordered_map<long long, long long> initial_n = get_exps(n);
    unordered_map<long long, long long> actual_n = get_exps(n);
    while (q > 0)
    {

        long long t;
        cin >> t;
        if (t == 2)
        {
            actual_n = initial_n;
        }
        else
        {
            long long x;
            cin >> x;
            unordered_map<long long, long long> x_exps = get_exps(x);
            actual_n = mix(actual_n, x_exps);
            unordered_map<long long, long long> d = get_exps(get_divisors(actual_n));
            if (dividess(actual_n, d))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        q--;
    }
    return;
}

int main()
{
    init();
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
        cout << endl;
    }
    return 0;
}
