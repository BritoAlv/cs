// Problem: B. Square or Not
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/B
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
    vector<char> s(n);
    forn
    {
        cin >> s[i];
    }
    int pointer = 0;
    int q = floor(sqrt(n));
    for (int i = q - 1; i <= q + 2; i++)
    {
        if (i * i == n)
        {
            int side = i;
            vector<vi> mat(i, vector<int>(side, 0));
            for (int row = 0; row < i; row++)
            {
                for (int col = 0; col < i; col++)
                {
                    mat[row][col] = int(s[pointer++] - '0');
                    if (row == 0 || col == 0 || row == i - 1 || col == i - 1)
                    {
                        if (!mat[row][col])
                        {
                            yesno(0);
                            return;
                        }
                    }
                    else
                    {
                        if (mat[row][col])
                        {
                            yesno(0);
                            return;
                        }
                    }
                }
            }
            yesno(1);
            return;
        }
    }
    yesno(0);
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
