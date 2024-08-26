// Problem: B. Matrix of Differences
// Contest: Codeforces - Educational Codeforces Round 141 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1783/problem/B
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
    int n;
    cin >> n;
    vector<vi> board(n, vi(n, 0));
    deque<int> A;
    for (int i = 0; i < n * n; i++)
    {
        A.pb(i + 1);
    }
    forn
    {
        if (even(i))
        {
            int pt_r = 0;
            int pt_c = i;
            while (pt_r < n && pt_c >= 0)
            {
                board[pt_r++][pt_c--] = A.front();
                A.pop_front();
            }
        }
        else
        {
            int pt_r = 0;
            int pt_c = i;
            while (pt_r < n && pt_c >= 0)
            {
                board[pt_r++][pt_c--] = A.back();
                A.pop_back();
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if ((n % 2 == 0 && odd(i)) || (n % 2 == 1 && even(i)))
        {
            int pt_r = i;
            int pt_c = n - 1;
            while (pt_r < n && pt_c >= 0)
            {
                board[pt_r++][pt_c--] = A.front();
                A.pop_front();
            }
        }
        else
        {
            int pt_r = i;
            int pt_c = n - 1;
            while (pt_r < n && pt_c >= 0)
            {
                board[pt_r++][pt_c--] = A.back();
                A.pop_back();
            }
        }
    }
    forn
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << wp;
        }
        cout << endl;
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
