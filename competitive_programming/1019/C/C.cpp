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

int sol(vi &a, int k)
{
    int n = a.size();
    vi mask(n), mask_s(n);
    forn mask[i] = a[i] + (i > 0 ? mask[i - 1] : 0);
    int upper = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        mask_s[i] = a[i] + (i < n - 1 ? mask_s[i + 1] : 0);
        if (2 * mask_s[i] - (n - i) >= 0)
        {
            if (upper == -1)
            {
                upper = i;
            }
        }
    }
    set<pi> P;
    for (int i = 0; i < n - 1; i++)
    {
        P.insert({(2 * mask[i] - (i + 1)), i});
    }
    for (int i = 0; i < n - 1; i++)
    {
        pi cur = {(2 * mask[i] - (i + 1)), i};
        P.erase(cur);
        if (cur.first >= 0)
        {
            auto pt = P.lower_bound({cur.first, -1});
            if (pt != P.end())
            {
                return 1;
            }
            if (upper != -1 && i < upper)
            {
                return 1;
            }
        }
    }
    return 0;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    forn cin >> a[i];
    forn a[i] = a[i] <= k;
    if (sol(a, k))
        cout << "YES" << endl;
    else
    {
        reverse(a.begin(), a.end());
        if (sol(a, k))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
