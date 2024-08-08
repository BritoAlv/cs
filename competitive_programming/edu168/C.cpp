// Problem: C. Even Positions
// Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1997/problem/C
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

void Solve()
{
    int n;
    cin >> n;
    vector<char> a(n);
    stack<int> op;
    forn
    {
        cin >> a[i];
    }
    a[0] = '(';
    for (int i = n - 2; i >= 2; i--)
    {
        if (a[i] == '_')
        {
            if (a[i - 1] == ')')
            {
                a[i] = '(';
            }
            else
            {
                a[i] = ')';
            }
        }
    }
    int ans = 0;
    forn
    {
        if (a[i] == '(')
        {
            op.push(i);
        }
        else
        {
            auto nx = op.top();
            op.pop();
            ans += (i - nx);
        }
    }
    cout << ans << endl;
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