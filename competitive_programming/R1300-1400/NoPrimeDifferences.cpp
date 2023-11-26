// Problem: C. No Prime Differences
// Contest: Codeforces - Codeforces Round 877 (Div. 2)
// URL: https://codeforces.com/contest/1838/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table;
    forn
    {
        table.push_back(vector<int>(m));
    }
    if (m % 2 == 0)
    {
        int offset = 1;
        forn
        {
            for (int j = 0; j < m; j++)
            {
                table[i][j] = offset++;
            }
        }
    }
    else if (n % 2 == 0)
    {
        int offset = 1;
        for (int j = 0; j < m; j++)
        {
            forn
            {
                table[i][j] = offset++;
            }
        }
    }
    else
    {
        int start = n - 1;
        for (int j = 1; j <= n; j += 2)
        {
            table[start][m - 1] = m * j;
            for (int i = m - 2; i >= 0; i--)
            {
                table[start][i] = table[start][i + 1] - 1;
            }
            start--;
        }
        for (int j = 2; j <= n; j += 2)
        {
            table[start][m - 1] = m * j;
            for (int i = m - 2; i >= 0; i--)
            {
                table[start][i] = table[start][i + 1] - 1;
            }
            start--;
        }
    }
    for (auto x : table)
    {
        for (auto y : x)
        {
            cout << y << wp;
        }
        cout << endl;
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
