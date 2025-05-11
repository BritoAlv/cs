// Problem: D. Flower Boy
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/contest/2106/problem/D
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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    forn
    {
        cin >> a[i];
    }
    form
    {
        cin >> b[j];
    }
    vi p(m, -1);
    vi s(m, -1);
    int pt = 0;
    forn
    {
        if (a[i] >= b[pt])
        {
            p[pt] = i;
            pt++;
            if (pt == m)
            {
                break;
            }
        }
    }
    pt = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= b[pt])
        {
            s[pt] = i;
            pt--;
            if (pt == -1)
                break;
        }
    }
    int minn = -1;
    // not remove anything.
    if (p[m - 1] != -1)
    {
        minn = 0;
    }
    // remove one of the b[i]s.
    for (int j = 0; j < m; j++)
    {
        if (j > 0 && p[j - 1] == -1)
        {
            continue;
        }
        if (j < m - 1 && s[j + 1] == -1)
        {
            continue;
        }
        if (j > 0 && j < m - 1)
        {
            if (p[j - 1] >= s[j + 1])
            {
                continue;
            }
        }
        if (minn == -1 || minn > b[j])
            minn = b[j];
    }
    cout << minn << endl;
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
