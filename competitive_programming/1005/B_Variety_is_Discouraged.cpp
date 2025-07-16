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
	fori(0, n-1) cin >> a[i];
    set<int> P;
    fori(0, n - 1) P.insert(a[i]);
    vector<pi> candidates;
    fori(0, n - 1)
    {
        set<int> vals;
        int ed = i;
        vals.insert(a[i]);
        while (ed + 1 < n && vals.count(a[ed+1]) == 0){
            ed++;
            vals.insert(a[ed]);
        }
        if(vals.size() == P.size()){
            cout << i + 1 << wp << ed + 1 << endl;
            return;
        }
        i = ed;
    }
    cout << 0 << endl;
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
