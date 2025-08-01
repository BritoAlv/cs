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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if(b < a){
        if(a % 2 == 1 && a == b+1){
            cout << y << endl;
            return;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    ll ans = 0;
    while (a < b)
    {
        if(a % 2 == 0){
            ans += min(x, y);
        } else{
            ans += x;
        }
        a++;
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
