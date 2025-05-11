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

int mb, mm, Mb, Mm;

int bs(int l, int r, int x, int pos_x, vi &a)
{
    mb = mm = Mb = Mm = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m - 1] == x)
            return 1;
        if (pos_x < m - 1)
        {
            // need a greater element.
            if (a[m - 1] > x)
            {
                Mb++;
            }
            else
            {
                Mm++;
            }
            r = m - 1;
        }
        else
        {
            // need a less element
            if (a[m - 1] < x)
            {
                mb++;
            }
            else
            {
                mm++;
            }
            l = m + 1;
        }
    }
    return 0;
}

void Solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi b(n);
    forn cin >> a[i];
    forn b[a[i] - 1] = i;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (!bs(l, r, x, b[x - 1], a))
        {
            cout << -1 << wp;
            continue;
        }
        int cand1 = 1e9 + 1;
        if (mm <= Mm && ((n - x) - (Mb + mm)) >= (Mm - mm))
        {
            cand1 = min(cand1, 2 * Mm);
        }
        if (Mm <= mm && ((x - 1) - (mb + Mm)) >= (mm - Mm))
        {
            cand1 = min(cand1, 2 * mm);
        }
        if (cand1 == 1e9 + 1)
        {
            cout << -1 << wp;
        }
        else
        {
            cout << cand1 << wp;
        }
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
