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
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    ll dist = (px - qx) * (px - qx) + (qy - py) * (qy - py);
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[n - 1] * a[n - 1] <= dist)
    {
        ll sum = 0;
        fori(0, n - 1) sum += a[i];
        sum *= sum;
        cout << ((sum >= dist) ? "YES" : "NO") << endl;
    }
    else
    {
        ll sum = 0;
        fori(0, n - 2) sum += a[i];
        ll dif = a[n - 1] - sum;
        cout << ( (dif <= 0 || dist >= dif * dif)  ? "YES" : "NO") << endl;
    }
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
