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

ll MOD = 998244353;

ll pow_2(int x)
{
    if (x == 0)
        return 1ll;
    ll half = pow_2(x / 2);
    half *= half;
    half %= MOD;
    if (x % 2)
    {
        half *= 2;
        half %= MOD;
    }
    return half;
}

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    vl q(n);
    fori(0, n - 1) cin >> q[i];
    vl ans(n);
    vector<pi> max_pos(n);
    fori(0, n - 1)
    {
        max_pos[i] = {i, i};
        if (i > 0)
        {
            if (a[i] < a[max_pos[i - 1].first])
            {
                max_pos[i].first = max_pos[i - 1].first;
            }
            if (q[i] < q[max_pos[i - 1].second])
            {
                max_pos[i].second = max_pos[i - 1].second;
            }
        }
        int pos1 = max_pos[i].first;
        int pos2 = max_pos[i].second;
        if (a[pos1] == q[pos2])
        {
            if (q[i - pos1] > a[i - pos2])
            {
                ans[i] = pow_2(q[i - pos1]) + pow_2(a[pos1]);
                ans[i] %= MOD;
            }
            else
            {
                ans[i] = pow_2(a[i - pos2]) + pow_2(q[pos2]);
                ans[i] %= MOD;
            }
        } else{
            if(a[pos1] > q[pos2]){
                ans[i] = pow_2(q[i - pos1]) + pow_2(a[pos1]);
                ans[i] %= MOD;
            } else{
                ans[i] = pow_2(a[i - pos2]) + pow_2(q[pos2]);
                ans[i] %= MOD;
            }
        }
    }
    fori(0, n - 1)
    {
        cout << ans[i] << wp;
    }
    cout << endl;
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
