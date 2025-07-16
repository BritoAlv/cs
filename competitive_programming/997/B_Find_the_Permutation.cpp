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
    vector<vector<char>> m(n, vector<char>(n));
    set<int> free;
    fori(0, n - 1)
    {
        free.insert(i + 1);
    }
    vi ans(n);
    fori(0, n - 1)
    {
        int deg1 = 0;
        int deg2 = 0;
        forj(0, n - 1) cin >> m[i][j];
        forj(i+1, n - 1) deg1 += (m[i][j] == '1');
        forj(0, i - 1) deg2 += (m[i][j] == '0');
        // find in free the smallest element >= deg;
        ans[n - (deg1 + deg2) - 1] = i + 1;
    }
    print(ans);
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
