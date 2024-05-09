// Problem: B. Rectangle Filling
// Contest: Codeforces - Codeforces Round 941 (Div. 2)
// URL: https://codeforces.com/contest/1966/problem/B
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

int paint(vector<vector<char>> &board)
{
    int n = board.sz;
    int m = board[0].sz;
    if (n == 1)
    {
        return board[0][0] == board[0][m - 1];
    }
    int flag1 = 1;
    form
    {
        if (board[0][0] != board[0][j])
        {
            flag1 = 0;
        }
        if (board[n - 1][0] != board[n - 1][j])
        {
            flag1 = 0;
        }
    }
    return !(flag1 && board[0][0] != board[n - 1][0]);
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board1;
    vector<vector<char>> board2;
    forn
    {
        board1.pb(vector<char>(m));
    }
    form
    {
        board2.pb(vector<char>(n));
    }
    forn
    {
        form
        {
            cin >> board1[i][j];
            board2[j][i] = board1[i][j];
        }
    }
    cout << ((paint(board1) && paint(board2)) ? "YES" : "NO") << endl;
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