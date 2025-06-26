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
    cout << 2 * n << endl;
    fori(0, n-1){
        cout << i + 1 << wp << 1 << wp <<  i + 1 << endl;
        cout << i + 1 << wp << min(n, i+2) << wp << n << endl;
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
