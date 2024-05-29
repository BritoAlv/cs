// Problem: B. Neighbor Grid
// Contest: Codeforces - Codeforces Global Round 9
// URL: https://codeforces.com/contest/1375/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    forn
    {
        form
        {
            cin >> board[i][j];
        }
    }
    forn
    {
        form
        {
            int exp_value = 4;
            int condition = (i == 0) + (i == n - 1) + (j == 0) + (j == m - 1);
            exp_value -= condition;
            if (board[i][j] > exp_value)
            {
                cout << "NO" << endl;
                return;
            }
            board[i][j] = exp_value;
        }
    }
    cout << "YES" << endl;
    forn
    {
        form
        {
            cout << board[i][j] << wp;
        }
        cout << endl;
    }
    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
