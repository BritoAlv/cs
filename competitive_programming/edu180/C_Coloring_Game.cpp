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
    vector<pi> a(n);
    fori(0, n - 1) cin >> a[i].first;
    fori(0, n - 1) a[i].second = i;
    sort(a.begin(), a.end());
    ll ans = 0;
    fori(0, n - 1)
    {
        forj(i + 1, n - 2)
        {
            pi to_find = {a[i].first + a[j].first, -1};
            auto pt = lower_bound(a.begin(), a.end(), to_find);
            int condition = a[n - 1].first - a[i].first - a[j].first;
            pi to_find2 = {condition, n};
            auto pt2 = lower_bound(a.begin(), a.end(), to_find2);
            if(pt == a.begin())
            {

            } else
            {
                pt--;
                int low = max(j + 1, ((*pt2).second));
                int up = (*pt).second;
                if(low <= up) {
                    ans += up - low + 1;
                    //cout << i << wp << j << wp << up - low + 1 << endl;
                }
            }
        }
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
