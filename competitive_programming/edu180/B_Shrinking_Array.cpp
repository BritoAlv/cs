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
    vl b(n);
    fori(0, n - 1) cin >> a[i];
    fori(0, n - 1) b[i] = a[i];
    reverse(b.begin(), b.end());
    if (n == 2)
    {
        if (abs(a[0] - a[1]) > 1)
            cout << -1 << endl;
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        fori(0, n - 2) if (abs(a[i] - a[i + 1]) <= 1)
        {
            cout << 0 << endl;
            return;
        };
        if (is_sorted(a.begin(), a.end()) || is_sorted(b.begin(), b.end()))
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
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
