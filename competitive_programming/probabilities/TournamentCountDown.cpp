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

int query(int a, int b)
{
    cout << "?" << wp << a << wp << b << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void ans(int a)
{
    cout << "!" << wp << a << endl;
    cout.flush();
}

void Solve()
{
    int n;
    cin >> n;
    vi alives((1 << n), 0);
    for (int i = 0; i < (1 << n); i++)
    {
        alives[i] = i + 1;
    }
    while (sz(alives) >= 4)
    {
        vi upd;
        for (int i = 0; i < sz(alives); i += 4)
        {
            int result = query(alives[i], alives[i + 2]);
            if (result == 0)
            {
                upd.pb(alives[i + 1]);
                upd.pb(alives[i + 3]);
            }
            if (result == 1)
            {
                upd.pb(alives[i]);
                upd.pb(alives[i + 3]);
            }
            if (result == 2)
            {
                upd.pb(alives[i + 2]);
                upd.pb(alives[i + 1]);
            }
        }
        alives = upd;
    }
    int result = query(alives[0], alives[1]);
    if (result == 1)
    {
        ans(alives[0]);
    }
    else
    {
        ans(alives[1]);
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