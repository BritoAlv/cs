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

int can_be_cost(vi &a, int cost, int k){
    int n = a.size();
    int to_find = 1;
    int i = 1;
    while (to_find <= cost)
    {
    }
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    for (int to_check = 1; to_check <= n; to_check++)
    {
        for (int i = to_check; 1 + (n-1) - (i+1) >= k - (2 * to_check) ; i++)
        {
            if (a[i] != to_check)
            {
                cout << to_check << endl;
                return;
            }
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
