// Problem: C. Colorful Grid
// Contest: Codeforces - Codeforces Round 910 (Div. 2)
// URL: https://codeforces.com/contest/1898/problem/C
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
#define pb push_back

using namespace std;

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k < n + m - 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        if ((k - (n + m - 2)) % 2 == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            if ((k - (n + m - 2)) % 4 == 0)
            {
                vector<vector<int>> hl;
                vector<vector<int>> vl;
                for (int i = 0; i < n; i++)
                {
                    hl.pb(vector<int>(m - 1, -1));
                }
                for (int i = 0; i < n - 1; i++)
                {
                    vl.pb(vector<int>(m, -1));
                }
                for (int i = 0; i < m - 1; i++)
                {
                    hl[0][i] = (i % 2 == 0);
                }
                vl[0][m - 1] = (hl[0][m - 2] == 1 ? 0 : 1);
                for (int i = 1; i < n - 1; i++)
                {
                    vl[i][m - 1] = (vl[i - 1][m - 1] == 1 ? 0 : 1);
                }
                hl[n - 1][m - 2] = vl[n - 2][m - 1] == 1 ? 0 : 1;
                hl[n - 2][m - 2] = hl[n - 1][m - 2];
                vl[n - 2][m - 2] = vl[n - 2][m - 1];

                hl[n - 1][m - 3] = hl[n - 1][m - 2] == 1 ? 0 : 1;
                hl[n - 2][m - 3] = hl[n - 1][m - 3];
                vl[n - 2][m - 3] = vl[n - 2][m - 2] == 1 ? 0 : 1;

                for (auto x : hl)
                {
                    for (auto y : x)
                    {
                        cout << (y == 1 ? 'R' : 'B') << wp;
                    }
                    cout << endl;
                }
                for (auto x : vl)
                {
                    for (auto y : x)
                    {
                        cout << (y == 1 ? 'R' : 'B') << wp;
                    }
                    cout << endl;
                }
            }
            else
            {
                vector<vector<int>> hl;
                vector<vector<int>> vl;
                for (int i = 0; i < n; i++)
                {
                    hl.pb(vector<int>(m - 1, -1));
                }
                for (int i = 0; i < n - 1; i++)
                {
                    vl.pb(vector<int>(m, -1));
                }
                vl[0][0] = 1;
                vl[0][1] = 1;
                hl[0][1] = 0;
                hl[1][0] = 0;
                for (int i = 2; i < m - 1; i++)
                {
                    hl[0][i] = (i % 2 == 0);
                }
                vl[0][m - 1] = (hl[0][m - 2] == 1 ? 0 : 1);
                for (int i = 1; i < n - 1; i++)
                {
                    vl[i][m - 1] = (vl[i - 1][m - 1] == 1 ? 0 : 1);
                }
                hl[n - 1][m - 2] = vl[n - 2][m - 1] == 1 ? 0 : 1;
                hl[n - 2][m - 2] = hl[n - 1][m - 2];
                vl[n - 2][m - 2] = vl[n - 2][m - 1];

                hl[n - 1][m - 3] = hl[n - 1][m - 2] == 1 ? 0 : 1;
                hl[n - 2][m - 3] = hl[n - 1][m - 3];
                vl[n - 2][m - 3] = vl[n - 2][m - 2] == 1 ? 0 : 1;

                for (auto x : hl)
                {
                    for (auto y : x)
                    {
                        cout << (y == 1 ? 'R' : 'B') << wp;
                    }
                    cout << endl;
                }
                for (auto x : vl)
                {
                    for (auto y : x)
                    {
                        cout << (y == 1 ? 'R' : 'B') << wp;
                    }
                    cout << endl;
                }
            }
        }
    }
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
