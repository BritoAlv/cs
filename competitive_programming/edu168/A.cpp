// Problem: A. Strong Password
// Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1997/problem/0
// Memory Limit: 512 MB
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
    string s;
    cin >> s;
    int n = s.sz;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            string r = "";
            for (int j = 0; j <= i; j++)
            {
                r += s[j];
            }
            for (int j = 0; j < 26; j++)
            {
                if ((char)('a' + j) != s[i])
                {
                    r += (char)('a' + j);
                    break;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                r += s[j];
            }
            cout << r << endl;
            return;
        }
    }
    if (n == 1)
    {
        for (int i = 0; i < 26; i++)
        {
            if ((char)('a' + i) != s[0])
            {
                cout << (char)('a' + i) << s << endl;
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if ((char)('a' + i) != s[n - 2] && (char)('a' + i) != s[n - 1])
            {
                for (int j = 0; j <= n - 2; j++)
                {
                    cout << s[j];
                }
                cout << (char)('a' + i);
                cout << s[n - 1] << endl;
                return;
            }
        }
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
