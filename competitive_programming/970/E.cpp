// Problem: E. Alternating String
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/E
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
    vector<int> A(n);
    forn
    {
        char x;
        cin >> x;
        A[i] = (int)(x - 'a');
    }
    vector<vi> pOdd(26, vi(n, 0));
    vector<vi> pEven(26, vi(n, 0));
    vector<vi> sOdd(26, vi(n, 0));
    vector<vi> sEven(26, vi(n, 0));
    int clet = 26;
    forn
    {
        if (odd(i))
        {
            pOdd[A[i]][i]++;
        }
        else
        {
            pEven[A[i]][i]++;
        }
    }
    for (int i = 0; i < clet; i++)
    {
        for (int j = 1; j < n; j++)
        {
            pOdd[i][j] += pOdd[i][j - 1];
            pEven[i][j] += pEven[i][j - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (odd(i))
        {
            sOdd[A[i]][i]++;
        }
        else
        {
            sEven[A[i]][i]++;
        }
    }
    for (int i = 0; i < clet; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            sOdd[i][j] += sOdd[i][j + 1];
            sEven[i][j] += sEven[i][j + 1];
        }
    }
    if (odd(n))
    {
        int ops = 1e9 + 1;
        forn
        {
            // at every position simulate remove of that position.
            int part_even = 0;
            int part_odd = 0;
            for (int l = 0; l < clet; l++)
            {
                part_even = max(part_even, (i > 0 ? pEven[l][i - 1] : 0) + (i < n - 1 ? sOdd[l][i + 1] : 0));
                part_odd = max(part_odd, (i > 0 ? pOdd[l][i - 1] : 0) + (i < n - 1 ? sEven[l][i + 1] : 0));
            }
            ops = min(ops, (i - part_even) + (n - 1 - i - part_odd));
        }
        cout << 1 + ops << endl;
    }
    else
    {
        int ops = 1e9 + 1;
        int part_even = 0;
        int part_odd = 0;
        for (int l = 0; l < clet; l++)
        {
            part_even = max(part_even, pEven[l][n - 1]);
            part_odd = max(part_odd, pOdd[l][n - 1]);
            ops = min(ops, n - part_even - part_odd);
        }

        cout << ops << endl;
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
