// Problem: D. Sakurako's Hobby
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/D
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
    int n;
    cin >> n;
    vi a(n);
    forn
    {
        cin >> a[i];
    }
    vi b(n);
    forn
    {
        char x;
        cin >> x;
        b[i] = (int)(x - '0');
    }
    set<int> done;
    vector<vi> groups;
    vi assig(n, 0);
    forn
    {
        if (!exist(done, i + 1))
        {
            done.insert(i + 1);
            assig[i] = sz(groups);
            groups.pb(vi({i + 1}));
            int st = a[i];
            while (!exist(done, st))
            {
                done.insert(st);
                groups.back().pb(st);
                assig[st - 1] = assig[i];
                st = a[st - 1];
            }
        }
    }
    vi ss(sz(groups), 0);
    forn
    {
        if (!b[i])
            ss[assig[i]]++;
    }
    forn
    {
        cout << ss[assig[i]] << wp;
    }
    cout << endl;
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
