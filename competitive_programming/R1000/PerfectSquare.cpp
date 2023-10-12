// Problem: C. Perfect Square
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/C
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
    int n;
    cin >> n;
    vector<vector<char>> M;
    forn
    {
        M.push_back(vector<char>(n));
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    long long answer = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            char great = M[a][b];
            if (M[n - 1 - b][a] > great)
            {
                great = M[n - 1 - b][a];
            }
            if (M[n - 1 - a][n - 1 - b] > great)
            {
                great = M[n - 1 - a][n - 1 - b];
            }
            if (M[b][n - 1 - a] > great)
            {
                great = M[b][n - 1 - a];
            }
            answer += (great - M[a][b]);
        }
    }
    cout << answer << endl;
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
