// Problem: B. Binary Typewriter
// Contest: Codeforces - Codeforces Round 1019 (Div. 2)
// URL: https://codeforces.com/contest/2103/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
    int n;
    cin >> n;
    vector<char> A(n + 1);
    A[0] = '0';
    forn cin >> A[i + 1];
    vector<int> pos1;
    vector<int> pos2;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == '0' && A[i + 1] == '1')
        {
            pos1.pb(i);
        }
        if (A[i] == '1' && A[i + 1] == '0')
        {
            pos2.pb(i);
        }
    }
    int good = pos1.size() >= 2 || pos2.size() >= 2;
    int st = 0;
    int ops = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (A[i] != char('0' + st))
        {
            st = !st;
            ops++;
        }
    }
    // cout << n << wp << ops << wp << good << endl;
    if (good)
    {
        cout << n + ops - 2 << endl;
    }
    else if (pos2.size() >= 1)
    {
        cout << n + ops - 1 << endl;
    }
    else
    {
        cout << n + ops << endl;
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
