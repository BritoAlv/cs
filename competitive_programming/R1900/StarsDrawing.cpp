// Problem: E1. Stars Drawing (Easy Edition)
// Contest: Codeforces - Codeforces Round 501 (Div. 3)
// URL: https://codeforces.com/contest/1015/problem/E1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back
#define ull unsigned long long
using namespace std;

int dpleft[1001][1001];
int dpright[1001][1001];
int dpup[1001][1001];
int dpdown[1001][1001];

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ta;
    forn
    {
        ta.pb(vector<char>(m));
        form
        {
            cin >> ta[i][j];
        }
    }
    forn
    {
        dpleft[i][0] = 0;
        for (int j = 1; j < m; j++)
        {
            if (ta[i][j] == '*' && ta[i][j - 1] == '*')
            {
                dpleft[i][j] = dpleft[i][j - 1] + 1;
            }
            else
            {
                dpleft[i][j] = 0;
            }
        }
    }
    forn
    {
        dpright[i][m - 1] = 0;
        for (int j = m - 2; j >= 0; j--)
        {
            if (ta[i][j] == '*' && ta[i][j + 1] == '*')
            {
                dpright[i][j] = dpright[i][j + 1] + 1;
            }
            else
            {
                dpright[i][j] = 0;
            }
        }
    }
    forn
    {
        form
        {
            if (i == 0)
            {
                dpup[i][j] = 0;
            }
            else
            {
                if (ta[i][j] == '*' && ta[i - 1][j] == '*')
                {
                    dpup[i][j] = dpup[i - 1][j] + 1;
                }
                else
                {
                    dpup[i][j] = 0;
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        form
        {
            if (i == n - 1)
            {
                dpdown[i][j] = 0;
            }
            else
            {
                if (ta[i][j] == '*' && ta[i + 1][j] == '*')
                {
                    dpdown[i][j] = dpdown[i + 1][j] + 1;
                }
                else
                {
                    dpdown[i][j] = 0;
                }
            }
        }
    }
    int dpresult[n][m];
    forn
    {
        form
        {
            if (ta[i][j] == '*')
            {
                dpresult[i][j] = min(min(dpup[i][j], dpdown[i][j]), min(dpleft[i][j], dpright[i][j]));
            }
            else
            {
                dpresult[i][j] = 0;
            }
        }
    }
    vector<set<pair<int, int>>> rows;
    vector<set<pair<int, int>>> columns;
    forn
    {
        rows.pb(set<pair<int, int>>());
    }
    form
    {
        columns.pb(set<pair<int, int>>());
    }
    forn
    {
        form
        {
            if (dpresult[i][j] > 0)
            {
                rows[i].insert({j - dpresult[i][j], j + dpresult[i][j]});
                columns[j].insert({i - dpresult[i][j], i + dpresult[i][j]});
            }
        }
    }
    forn
    {
        set<pair<int, int>> copy;
        for (auto x : rows[i])
        {
            if (copy.size() == 0 || x.second > (*(copy.rbegin())).second)
            {
                copy.insert(x);
            }
        }
        rows[i] = copy;
    }
    form
    {
        set<pair<int, int>> copy;
        for (auto x : columns[j])
        {
            if (copy.size() == 0 || x.second > (*(copy.rbegin())).second)
            {
                copy.insert(x);
            }
        }
        columns[j] = copy;
    }
    vector<vector<int>> ANS;
    forn
    {
        form
        {
            if (dpresult[i][j] == 0 && ta[i][j] == '*')
            {
                int found = 0;
                for (auto &y : rows[i])
                {
                    if (j >= y.first && j <= y.second)
                    {
                        found = 1;
                        ANS.pb({i, (y.first + y.second) / 2, (y.second - y.first) / 2});
                        break;
                    }
                }
                if (!found)
                {
                    for (auto &y : columns[j])
                    {
                        if (i >= y.first && i <= y.second)
                        {
                            found = 1;
                            ANS.pb({(y.first + y.second) / 2, j, (y.second - y.first) / 2});
                            break;
                        }
                    }
                }
                if (!found)
                {
                    cout << -1 << endl;
                    return;
                }
            }
            else if (dpresult[i][j] > 0 && ta[i][j] == '*')
            {
                ANS.pb({i, j, 1});
            }
        }
    }
    cout << ANS.size() << endl;
    for (auto x : ANS)
    {
        cout << x[0] + 1 << wp << x[1] + 1 << wp << x[2] << endl;
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
