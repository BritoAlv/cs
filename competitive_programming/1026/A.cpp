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
    sort(a.begin(), a.end());
    int first_o = -1;
    int first_e = -1;
    int last_o = -1;
    int last_e = -1;
    fori(0, n - 1)
    {
        if (a[i] % 2 && first_o == -1)
            first_o = i;
        if (a[i] % 2 == 0 && first_e == -1)
            first_e = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] % 2 && last_o == -1)
            last_o = i;
        if (a[i] % 2 == 0 && last_e == -1)
            last_e = i;
    }
    if (first_o == -1 || first_e == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        int ans = 1e9 + 1;
        if (last_o - first_o >= 0)
            ans = n - (last_o - first_o + 1);
        if (last_e - first_e >= 0)
            ans = min(ans, n - (last_e - first_e + 1));
        cout << ans << endl;
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
