// Problem: D. Bag of mice
// Contest: Codeforces - Codeforces Round 105 (Div. 2)
// URL: https://codeforces.com/contest/148/problem/D
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

double p(ll a, ll b)
{
    double r = a;
    r /= (double)(b + a);
    return r;
}

void Solve()
{
    int a, b;
    cin >> a >> b;
    vector<vector<double>> ans(1000 + 1, vector<double>(1000 + 1, 0));
    for (int aa = 1; aa <= a; aa++)
    {
        for (int i = 0; i <= 2; i++)
        {
            ans[aa][i] = p(aa, i);
        }
        ans[aa][2] += p(2, aa) * p(1, aa);
    }
    for (int aa = 1; aa <= a; aa++)
    {
        for (int i = 3; i <= b; i++)
        {
            ans[aa][i] = p(aa, i);
            double prob_space = p(i, aa) * p(i - 1, aa);

            double case_1 = p(aa, i - 2) * ans[aa - 1][i - 2];
            double case_2 = p(i - 2, aa) * ans[aa][i - 3];

            double sum = case_1 + case_2;
            ans[aa][i] += prob_space * sum;
        }
    }
    printf("%.9f", ans[a][b]);
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