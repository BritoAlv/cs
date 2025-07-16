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
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    vector<ll> min_arr(n);
    min_arr[0] = a[0];
    fori(1, n - 1)
    {
        min_arr[i] = min(min_arr[i - 1], a[i]);
    }
    fori(1, n - 1)
    {
        min_arr[i] += min_arr[i - 1];
    }
    vector<ll> difs(n, 2 * n);
    fori(1, n - 1)
    {
        difs[i] = max(0ll, a[i - 1] - a[i]);
        difs[i] = min(difs[i], difs[i - 1]);
    }
    ll best = min(a[0] + a[1], min_arr[n-1]);
    fori(2, n - 1)
    {
        best = min(best, min_arr[i - 1] + min(a[i], difs[i - 1]));
    }
    cout << best << endl;
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
