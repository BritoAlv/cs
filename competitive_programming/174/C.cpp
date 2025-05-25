// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define wp(x, y) (x == y ? '\n' : ' ')
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)

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
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    vi dp(n, 0);
    ll cur = 0;
    ll reds = 0;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 2)
        {
            cur *= 2;
            cur %= 998244353;
        }
        else if (a[i] == 3)
        {
            cur += 1;
            cur %= 998244353;
            reds++;
        }
        else
        {
            ans -= reds;
        }
        dp[i] = cur;
    }
    ans += 998244353;
    ans %= 998244353;
    // print(dp);
    fori(0, n - 1)
    {
        if (a[i] == 1)
        {
            ans += dp[i];
            ans %= 998244353;
        }
    }
    cout << ans << wp(0, 0);
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
