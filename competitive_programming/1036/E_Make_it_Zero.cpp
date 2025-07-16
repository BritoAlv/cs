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

void op(vl &a, int st, int ed, int center, ll x)
{
    vl res(a.size());
    res[center] = x;
    a[center] -= x;
    for (int i = st; i <= ed && x > 0; i++)
    {
        ll rem = min(a[i], x);
        a[i] -= rem;
        x -= rem;
        res[i] = rem;
    }
    print(res);
}

void solve(vl &a)
{
    int n = a.size();
    ll maxx = 0;
    fori(0, n - 1) maxx = max(maxx, a[i]);
    ll sum = 0;
    fori(0, n - 1) sum += a[i];
    if (sum - maxx < maxx || sum % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    // check if possible with one operation.
    ll sum1 = 0;
    ll sum2 = 0;
    fori(0, n - 1) sum2 += a[i];
    fori(0, n - 2)
    {
        sum1 += a[i];
        sum2 -= a[i];
        if (sum1 == sum2)
        {
            cout << 1 << endl;
            print(a);
            return;
        }
    }
    // if two operations, then find a position not in the borders, that have the property.
    sum1 = a[0];
    sum2 = 0;
    fori(1, n - 1) sum2 += a[i];
    fori(1, n - 2)
    {
        if (sum1 <= sum2 && sum1 + a[i] >= sum2 - a[i])
        {
            ll x = (sum1 - (sum2 - 2 * a[i])) /2;
            cout << 2 << endl;
            op(a, 0, i-1, i, x);
            print(a);
            return;
        }
        else
        {
            sum1 += a[i];
            sum2 -= a[i];
        }
    }

    sum1 = a[n - 1];
    sum2 = 0;
    fori(0, n - 2) sum2 += a[i];

    for (int i = n - 2; i >= 1; i--)
    {
        if (sum1 <= sum2 && sum1 + a[i] >= sum2 - a[i])
        {
            ll x = (sum1 + sum2 - 2 * a[i]);
            cout << 2 << endl;
            op(a, i+1, n-1, i, x);
            print(a);
            return;
        }
        else
        {
            sum1 += a[i];
            sum2 -= a[i];
        }
    }
    cout << -1 << endl;
}

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    fori(0, n - 1) cin >> a[i];
    solve(a);
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