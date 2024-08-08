// Problem: B1. Bouquet (Easy Version)
// Contest: Codeforces - Codeforces Round 961 (Div. 2)
// URL: https://codeforces.com/contest/1995/problem/B1
// Memory Limit: 512 MB
// Time Limit: 1500 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
#define print(x, name)                                                                                                 \
    cout << name << endl;                                                                                              \
    for (auto z : x)                                                                                                   \
        cout << z << wp;                                                                                               \
    cout << endl;
// je m appelle Alvaro j ai 21 ans.
int test_cases;
int test_cases_original;
#define t_number test_cases_original - test_cases

using namespace std;

ll ceil(ll a, ll b)
{
    return a / b + (a % b != 0);
}

ll floor(ll a, ll b)
{
    return a / b;
}

void Solve()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> count;
    vl a(n);
    vl b(n);
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    forn
    {
        count[a[i]] = b[i];
    }
    ll maxx = 0;
    for (auto x : count)
    {
        if (exist(count, x.first - 1))
        {
            ll rem = m;
            auto y = *count.find(x.first - 1);
            ll cantidad1 = min(x.second, m / x.first);
            rem -= cantidad1 * x.first;
            ll cantidad2 = min(y.second, rem / y.first);
            rem -= cantidad2 * y.first;
            if (maxx < m - rem)
            {
                maxx = m - rem;
            }
            ll exp_rem = ((y.first + 1) - m % (y.first + 1));
            ll k = y.first + 1;
            ll num = y.second;
            if (y.second >= exp_rem)
            {
                if (y.second % k >= exp_rem)
                {
                    num -= (num % k - exp_rem);
                }
                else
                {
                    num -= num % k;
                    num -= (k - exp_rem);
                }
            }
            if (num * y.first >= m)
            {
                ll dif = num * y.first - m;
                num -= k * min(num / k, dif / (k * y.first));
            }
            while (num * y.first >= m && num - k >= 0)
            {
                num -= k;
            }
            ll pt1 = ((m - num * y.first) / (x.first));
            ll pt2 = ((m - exp_rem * y.first) / (x.first));
            if (y.second >= exp_rem && ((pt1 <= x.second && pt1 >= 0) || (pt2 <= x.second && pt2 >= 0)))
            {
                maxx = m;
            }
        }
        ll cantidad = min(x.second, m / x.first);
        if (maxx < cantidad * x.first)
        {
            maxx = cantidad * x.first;
        }
    }
    cout << maxx << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> test_cases_original;
    test_cases = test_cases_original;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}