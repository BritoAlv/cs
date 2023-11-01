// Problem: D. X-Sum
// Contest: Codeforces - Codeforces Round 790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, m;
    cin >> n >> m;
    int pos_diag[n + m - 1];
    int neg_diag[n + m - 1];
    for (int i = 0; i < n + m - 1; i++)
    {
        pos_diag[i] = 0;
        neg_diag[i] = 0;
    }
    vector<vector<int>> table;
    forn
    {
        table.push_back(vector<int>(m));
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
            pos_diag[i + j] += table[i][j];
            neg_diag[j - i + n - 1] += table[i][j];
        }
    }
    int maxx = pos_diag[0 + 0] + neg_diag[n - 1] - table[0][0];
    forn
    {
        for (int j = 0; j < m; j++)
        {
            maxx = max(maxx, pos_diag[i + j] + neg_diag[j - i + (n - 1)] - table[i][j]);
        }
    }
    cout << maxx << endl;

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
