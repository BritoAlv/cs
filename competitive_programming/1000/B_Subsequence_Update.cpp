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
	int n, l, r;
	cin >> n >> l >> r;
    l--, r--;
    vl a(n);
    fori(0, n-1) cin >> a[i];
    vi one;
    vi two;
    fori(0, r) one.push_back(a[i]);
    fori(l, n - 1) two.push_back(a[i]);
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    ll s1 = 0;
    ll s2 = 0;
    fori(0, r - l){
        s1 += one[i];
        s2 += two[i];
    }
    cout << min(s1, s2) << endl;
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
