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

int do_query(int l, int m)
{
    cout << "?" << wp << l << wp << m << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int print_ans(int k)
{
    cout << "!" << wp << k << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int works(int n, int k, int m)
{
    int pt = 1;
    fork
    {
        if (pt == n + 1)
        {
            return 0;
        }
        pt = do_query(pt, m);
        if (pt == n + 1)
        {
            return 0;
        }
        pt++;
    }
    return pt == n + 1;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    int maxx = n;
    for (int i = n; i >= 1; i--)
    {
        int rs = do_query(1, maxx * n);
        if (rs != n + 1)
        {
            break;
        }
        else
        {
            maxx--;
        }
    }
    for (int t = 1; t <= n / k; t++)
    {
        if (works(n, k, t * maxx))
        {
            print_ans(t * maxx);
            return;
        }
    }
    print_ans(-1);
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
