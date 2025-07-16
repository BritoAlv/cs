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
    vector<pl> columns(n);
    fori(0, n - 1)
    {
        cin >> columns[i].first;
    }
    fori(0, n - 1)
    {
        cin >> columns[i].second;
    }
    ll best = -1e18;
    fori(0, n - 1)
    {
        ll apport = columns[i].first + columns[i].second;
        forj(0, n-1){
            if(j != i){
                apport += max(columns[j].first, columns[j].second);
            }
        }
        best = max(apport, best);
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
