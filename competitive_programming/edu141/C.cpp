// Problem: C. Yet Another Tournament
// Contest: Codeforces - Educational Codeforces Round 141 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1783/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int s1(vi &a, int j, int m)
{
    // I lose with this player.
    // this player will have j+1 victories,
    // thus I need that the su
    vi arr;
    for (int i = 0; i < sz(a); i++)
    {
        if (i != j)
        {
            arr.pb(a[i]);
        }
    }
    sort(all(arr));
    for (int i = 1; i < sz(arr); i++)
    {
        arr[i] += arr[i - 1];
    }
    int marker = 0;
    for (int i = 0; i < sz(arr); i++)
    {
        if (arr[i] <= m)
        {
            marker++;
        }
    }
    return (marker >= j + 1);
}

int s2(vi &a, int j, int m)
{
    if (a[j] > m)
    {
        return 0;
    }
    // I win to this player
    // thus I only need j wins.
    vi arr;
    for (int i = 0; i < sz(a); i++)
    {
        if (i != j)
        {
            arr.pb(a[i]);
        }
    }
    sort(all(arr));
    int marker = 1;
    for (int i = 1; i < sz(arr); i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < sz(arr); i++)
    {
        if (arr[i] <= m - a[j])
        {
            marker++;
        }
    }
    return (marker >= j);
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    forn
    {
        cin >> a[i];
    }
    if (!(s1(a, 0, m) || s2(a, 0, m)))
    {
        cout << n + 1 << endl;
        return;
    }
    int st = 0;
    int ed = n - 1;
    while (ed - st > 1)
    {
        int middle = st + (ed - st) / 2;
        if (s1(a, n - 1 - middle, m) || s2(a, n - 1 - middle, m))
        {
            ed = middle;
        }
        else
        {
            st = middle + 1;
        }
    }
    if (ed - 1 >= 0 && (s1(a, (n - 1) - (ed - 1), m) || s2(a, (n - 1) - (ed - 1), m)))
    {
        ed--;
    }
    cout << ed + 1 << endl;
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
