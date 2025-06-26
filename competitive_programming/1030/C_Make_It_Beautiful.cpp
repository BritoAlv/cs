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

int ans;

vector<ll> beauty_possible(ll x)
{
    vector<ll> active;
    for (int i = 0; i <= 62; i++)
    {
        int is_active = ((x & (1ll << i)) != 0);
        if (!is_active)
        {
            active.push_back((1ll << i));
        }
        else
        {
            ans++;
        }
    }

    return active;
    // count number of bits of x.
    // what to sum to x, so that its number of bits increase by one, by two.
    // smallest number with t active bits is 2^{i+1} - 1.
    // but if number is greater, I think that it is is remainder mod
}

void Solve()
{
    ll n, k;
    cin >> n >> k;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    vector<ll> possible;
    ans = 0;
    fori(0, n - 1) // 5000
    {
        auto r = beauty_possible(a[i]); // 64
        for (auto z : r)
        {
            possible.push_back(z);
        }
    }
    sort(possible.begin(), possible.end());
    //print(possible);
    fori(0, possible.size() - 1)
    {
        if (k < possible[i])
        {
            break;
        }
        else
        {
            ans++;
            k -= possible[i];
        }
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
