// Problem: B. Matrix Stabilization
// Contest: Codeforces - Codeforces Round 954 (Div. 3)
// URL: https://codeforces.com/contest/1986/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
            vector<int> neigbours;
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, -1, 0, 1};
            for (int z = 0; z < 4; z++)
            {
                if (i + dx[z] >= 0 && i + dx[z] < n && j + dy[z] >= 0 && j + dy[z] < m)
                {
                    neigbours.pb(board[i + dx[z]][j + dy[z]]);
                }
            }
            sort(neigbours.begin(), neigbours.end());
            board[i][j] = min(board[i][j], neigbours.back());
            cout << board[i][j] << wp;
        }
        cout << endl;
    }

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