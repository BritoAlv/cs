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
    fori(0, n - 1) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set<int> one;
    set<int> two;
    fori(0, n - 1) one.insert(a[i]);
    fori(0, n - 1) two.insert(b[i]);
    int flag = 1;
    if(one.size() == 1){
        flag &= two.size() >= 3;
    } 
    if(two.size() == 1){
        flag &= one.size() >= 3;
    }
    if(one.size() == 2){
        flag &= two.size() >= 2;
    }
    if(two.size() == 2){
        flag &= one.size() >= 2;
    }
    cout << (flag ? "YES" : "NO") << endl;
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
