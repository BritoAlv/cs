// Problem: B. GCD Partition
// Contest: Codeforces - Codeforces Round 846 (Div. 2)
// URL: https://codeforces.com/contest/1780/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define even(x) ((x) % 2 == 0)
#define odd(x) ((x) % 2 == 1)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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

ll mcd(ll a, ll b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, a % b);
    }
}

void Solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn
    {
        cin >> a[i];
    }
    ll mcdd = 1;
    vector<ll> psums(n);
    vector<ll> ssums(n);
    forn
    {
        psums[i] = a[i] + (i > 0 ? psums[i - 1] : 0);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ssums[i] = a[i] + (i < n - 1 ? ssums[i + 1] : 0);
    }
    for (int i = 0; i < n - 1; i++)
    {
        mcdd = max(mcdd, mcd(psums[i], ssums[i + 1]));
    }
    cout << mcdd << endl;
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
