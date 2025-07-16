// Problem: C. Increasing Sequence with Fixed OR
// Contest: Codeforces - Codeforces Round 958 (Div. 2)
// URL: https://codeforces.com/contest/1988/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
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

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

template <typename K, typename V> void print(const std::map<K, V> &m)
{
    for (const auto &[key, value] : m)
    {
        std::cout << key << ": " << value << "\n";
    }
}

int test_cases;
using namespace std;

void Solve()
{
    ll n;
    cin >> n;
    vector<ll> bit(64, 0);
    int active_bits = 0;
    fori(0, 63)
    {
        bit[i] = (n & (1ll << i)) > 0;
        active_bits += bit[i];
    }
    vl c;
    for (int i = 63; i >= 0; i--)
    {
        if (bit[i])
        {
            ll num = 0;
            forj(0, 63)
            {
                if (j != i && bit[j])
                {
                    num += (1ll << j);
                }
            }
            if (num > 0)
            {
                c.push_back(num);
            }
        }
    }
    c.push_back(n);
    fori(1, (int)c.size() - 1)
    {
        assert(c[i] > c[i - 1] && (c[i] | c[i - 1]) == n);
    }
    cout << c.size() << endl;
    fori(0, (int)c.size() - 1)
    {
        cout << c[i] << wp;
    }
    cout << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}