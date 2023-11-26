// Problem: D. Two-Colored Dominoes
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: notice that if in some row there is LR, then in some other row but in the same column have to be another LR, likewise with UD, that unlocks the problem
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> t;
    int works = 1;
    forn
    {
        t.push_back(vector<char>(m));
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> t[i][j];
            count += (t[i][j] != '.');
        }
        if (count % 2 != 0)
        {
            works = 0;
        }
    }

    for (int j = 0; j < m; j++)
    {
        int count = 0;
        forn
        {
            count += (t[i][j] != '.');
        }
        if (count % 2 != 0)
        {
            works = 0;
        }
    }
    if (works)
    {
        forn
        {
            for (int j = 0; j < m; j++)
            {
                if (t[i][j] == 'L')
                {
                    t[i][j] = 'W';
                    t[i][j + 1] = 'B';
                    for (int l = i + 1; l < n; l++)
                    {
                        if (t[l][j] == 'L')
                        {
                            t[l][j] = 'B';
                            t[l][j + 1] = 'W';
                            break;
                        }
                    }
                }

                if (t[i][j] == 'U')
                {
                    t[i][j] = 'W';
                    t[i + 1][j] = 'B';
                    for (int l = j + 1; j < m; l++)
                    {
                        if (t[i][l] == 'U')
                        {
                            t[i][l] = 'B';
                            t[i + 1][l] = 'W';
                            break;
                        }
                    }
                }
                cout << t[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << -1 << endl;
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
