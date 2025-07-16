// Problem: A. Simple Permutation
// Contest: Codeforces - Codeforces Round 1012 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2089/A
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

const int N = 100000 + 1;
vi smallest_divisor(N);
set<int> primes;

void init()
{
    fori(0, N - 1) smallest_divisor[i] = i;
    fori(2, N - 1)
    {
        if (smallest_divisor[i] == i)
        {
            primes.insert(i);
            for (int j = 2 * i; j < N; j += i)
            {
                if (smallest_divisor[j] == j)
                    smallest_divisor[j] = i;
            }
        }
    }
}

int smaller_prime(int x)
{
    auto pt = primes.lower_bound(x);
    return *pt;
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
    int n;
    cin >> n;
    vl p(n);
    set<int> options;
    fori(0, n - 1)
    {
        options.insert(i + 1);
    }
    int prime = smaller_prime((n / 3) / 2);
    // cout << prime << endl;
    vl p2(n);
    p2[0] = prime;
    for (int i = 1; i < n; i++)
    {
        int offset = i / 2 + (i % 2 == 1);
        int sign = (i % 2 == 0 ? -1 : 1);
        p2[i] = prime + sign * offset;
    }
    fori(0, n - 1)
    {
        if (p2[i] >= 1 && p2[i] <= n)
        {
            p[i] = p2[i];
            options.erase(p[i]);
        }
        else
        {
            forj(i, n - 1)
            {
                p[j] = *options.begin();
                options.erase(p[j]);
            }
            break;
        }
    }
    // print(p);
    set<int> q;
    fori(0, n - 1) q.insert(p[i]);
    assert(q.size() == n);
    int pp = 0;
    ll sum = 0;
    fori(0, n - 1)
    {
        assert(1 <= p[i] && p[i] <= n);
        sum += p[i];
        ll pr = sum / (i + 1);
        if (primes.count(pr))
            pp++;
    }
    assert(pp >= n / 3 - 1);
    print(p);
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