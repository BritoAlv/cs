// Problem: C1. Message Transmission Error (easy version)
// Contest: Codeforces - Testing Round 19 (Div. 3)
// URL: https://codeforces.com/contest/2010/problem/C1
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

void Solve()
{
    string s;
    cin >> s;
    int n = sz(s);
    for (int len_s = n / 2 + 1; len_s <= n - 1; len_s++)
    {
        string msg = "";
        for (int i = n - len_s; i < n; i++)
        {
            msg += s[i];
        }
        int works = 1;
        for (int i = 0; i < len_s; i++)
        {
            if (s[i] != msg[i])
            {
                works = 0;
            }
        }
        if (works)
        {
            yesno(1);
            cout << msg << endl;
            return;
        }
    }
    yesno(0);
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