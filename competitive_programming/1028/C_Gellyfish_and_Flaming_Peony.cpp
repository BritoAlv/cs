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

void ins(map<int, int> &D, pi A){
    if(D.count(A.first) == 0){
        D[A.first] = A.second;
    } else{
        D[A.first] = min(A.second, D[A.first]);
    }
}

void Solve()
{
	int n;
	cin >> n;
	vi a(n);
    map<int, int> D;
    fori(0, n - 1)
    {
        cin >> a[i];
        for (auto z : D){
            int mcd = __gcd(a[i], z.first);
            if(mcd != z.first){
                ins(D, {mcd, z.second + 1});
            }
        }
        ins(D, {a[i], 0});
    }
    int final = a[0];
    fori(1, n - 1) final = __gcd(a[i], final);
    int cost = D[final];
    int ans = 0;
    fori(0, n - 1) ans += a[i] == final;
    if(ans > 0){
        cout << n - ans << endl;
    } else{
        cout << n - 1 +cost << endl;
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