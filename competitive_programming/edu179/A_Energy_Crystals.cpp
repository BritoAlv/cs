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
    int x;
    cin >> x;
    vi sol(3, 0);
    int ans = 0;
    while (sol[0] != x || sol[2] != x)
    {
        sol[0] = 2 * sol[1] + 1;
        sol[0] = min(x, sol[0]);
        sort(sol.begin(), sol.end());
        ans++;
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
