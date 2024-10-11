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

int cant(int l, int r, int p)
{
    int sm;
    int gt;
    if (l % p == 0)
    {
        sm = l;
    }
    else
    {
        sm = l - (l % p) + p;
    }
    if (sm > r)
    {
        return 0;
    }
    gt = r - r % p;
    return (gt - sm) / p + 1;
}

void Solve()
{
    int n, p;
    cin >> n >> p;
    vector<pi> inte(n);
    forn
    {
        cin >> inte[i].first >> inte[i].second;
    }
    vector<double> exp(n, 0);
    forn
    {
        vi nn = {i, (n + (i + 1)) % n};
        vector<double> pp;
        vector<double> len;
        for (auto x : nn)
        {
            double v1 = (double)cant(inte[x].first, inte[x].second, p);
            double len1 = inte[x].second - inte[x].first + 1;
            pp.pb(v1);
            len.pb(len1);
        }
        exp[i] = 1 - (1 - pp[0] / len[0]) * (1 - pp[1] / len[1]);
    }
    double sum = 0;
    forn
    {
        sum += exp[i];
    }
    printf("%.9f", sum * 2000);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}