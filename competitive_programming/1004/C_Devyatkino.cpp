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

ll pow(ll exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return 10;
    ll half = pow(exp / 2);
    half *= half;
    if (exp % 2)
        half *= 10;
    return half;
}

ll valid(ll rem)
{
    while (rem > 0)
    {
        int seven = ((rem % 10) == 7);
        if (seven)
            return 1;
        rem /= 10;
    }
    return 0;
}

void Solve()
{
    ll n;
    cin >> n;
    ll ans = 9;
    for (int i = 1; i < 10; i++)
    {
        ll pow_1 = pow(i);
        ll to_add = pow(i) - 1;
        ll rem = n;
        ll candidate = 0;
        while (!valid(rem))
        {
            rem += to_add;
            candidate++;
        }
        //cout << i << wp << candidate << endl;
        ans = min(ans, candidate);
    }
    cout << ans << endl;
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
