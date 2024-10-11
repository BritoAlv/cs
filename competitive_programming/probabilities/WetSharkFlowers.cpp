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
        // the prob that receives 0
        // the prob that receives 1
        // the prob that receives 2
        vi nn = {(n + (i - 1)) % n, i, (n + (i + 1)) % n};
        vector<double> probs;
        for (auto x : nn)
        {
            double num = (double)(cant(inte[x].first, inte[x].second, p));
            double den = (double)(inte[x].second - inte[x].first + 1);
            probs.pb(num / den);
        }
        for (int j = 1; j < 8; j++)
        {
            vi s(3, 0);
            s[0] = (j & (1 << 0)) > 0;
            s[1] = (j & (1 << 1)) > 0;
            s[2] = (j & (1 << 2)) > 0;
            int count = s[0] + s[1] + s[2];
            double prob = 1;
            for (int jj = 0; jj < 3; jj++)
            {
                if (s[jj])
                    prob *= probs[jj];
                else
                    prob *= (1 - probs[jj]);
            }
            if (count >= 2 || j == 2)
                prob *= 2;
            exp[i] += prob;
        }
    }
    double sum = 0;
    forn
    {
        sum += exp[i];
    }
    printf("%.9f", sum * 1000);
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