// Problem: C. Cherry Bomb
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/contest/2106/problem/C
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

void Solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi b(n);
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    int only = 1;
    int sum = -1;
    forn
    {
        if (b[i] != -1)
        {
            only = 0;
            int new_sum = a[i] + b[i];
            if (sum != -1 && new_sum != sum)
            {
                cout << 0 << endl;
                return;
            }
            else
            {
                sum = new_sum;
            }
        }
    }
    if (!only)
    {
        forn
        {
            int candidate = sum - a[i];
            if (b[i] == -1 && candidate >= 0 && candidate <= k)
            {
            }
            else if (b[i] == -1)
            {
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
    }
    else
    {
        int minn = -1;
        int maxx = -1;
        forn
        {
            if (minn == -1 || minn > a[i])
            {
                minn = a[i];
            }
            if (maxx == -1 || maxx < a[i])
            {
                maxx = a[i];
            }
        }
        cout << max(0, k + minn - maxx + 1) << endl;
    }
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
