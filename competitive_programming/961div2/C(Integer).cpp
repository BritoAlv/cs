#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define sz size()
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

int is_valid(vi &a)
{
    int n = a.sz;
    int lone = -1;
    int mtwo = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            lone = i;
        }
        else if (mtwo == -1)
        {
            mtwo = i;
        }
    }
    if (mtwo != -1 && lone != -1 && lone > mtwo)
    {
        return -1;
    }
    return lone + 1;
}

void Solve()
{
    int n;
    cin >> n;
    vi b(n);
    vi dp(n, 0);
    forn
    {
        cin >> b[i];
    }
    auto st = is_valid(b);
    if (st == -1)
    {
        cout << -1 << endl;
        return;
    }
    forn
    {
        if (i > 0)
        {
            ll one = b[i - 1];
            ll two = b[i];
            int pp = dp[i - 1];
            while (one <= two && pp > 0)
            {
                one *= one;
                pp--;
            }
            if (two < one)
            {
                while (two < one)
                {
                    two = two * two;
                    dp[i]++;
                }
                dp[i] += pp;
            }
        }
    }
    ll ops = 0;
    forn
    {
        ops += dp[i];
    }
    cout << ops << endl;
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