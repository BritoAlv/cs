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
    sort(a.begin(), a.end());
    set<int> second;
    for (int i = n - 1; i >= 0; i--)
    {
        if (second.count(-a[i]) == 0)
        {
            second.insert(-a[i]);
        } else if((*second.begin()) == -a[i]){
            second.erase(-a[i]);
        } else{
            a[i]++;
            i++;
        }
    }
    cout << ((second.size() == 0) ? "Yes" : "No") << endl;
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
