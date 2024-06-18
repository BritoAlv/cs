// Problem: F. L-shapes
// Contest: Codeforces - Codeforces Round 817 (Div. 4)
// URL: https://codeforces.com/contest/1722/problem/F
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

int n, m;

int inside_board(int a, int b)
{
    return a >= 0 && a < n && b >= 0 && b < m;
}

vector<vector<int>> visited;
vector<vector<char>> board;

set<pi> reachable(int x, int y)
{
    set<pi> result;
    result.insert({x, y});
    visited[x][y] = 1;
    vector<pi> neig;
    neig.pb({x + 1, y});
    neig.pb({x - 1, y});
    neig.pb({x, y + 1});
    neig.pb({x, y - 1});
    for (auto z : neig)
    {
        if (inside_board(z.first, z.second) && board[z.first][z.second] == '*' && !visited[z.first][z.second])
        {
            for (auto zz : reachable(z.first, z.second))
            {
                result.insert(zz);
                if (result.sz > 3)
                {
                    return result;
                }
            }
        }
    }
    return result;
}

int diag_reachable(set<pi> cells)
{
    for (auto x : cells)
    {
        vector<pi> neig;
        neig.pb({x.first + 1, x.second + 1});
        neig.pb({x.first + 1, x.second - 1});
        neig.pb({x.first - 1, x.second + 1});
        neig.pb({x.first - 1, x.second - 1});
        for (auto y : neig)
        {
            if (inside_board(y.first, y.second) && board[y.first][y.second] == '*' &&
                cells.find({y.first, y.second}) == cells.end())
            {
                return 0;
            }
        }
    }
    return 1;
}

void Solve()
{
    cin >> n >> m;
    board = vector<vector<char>>(n, vector<char>(m));
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
            if (board[i][j] == '*')
            {
                visited = vector<vector<int>>(n, vector<int>(m, 0));
                auto t = reachable(i, j);
                if (t.sz != 3)
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    set<int> pt1;
                    set<int> pt2;
                    for (auto r : t)
                    {
                        pt1.insert(r.first);
                        pt2.insert(r.second);
                    }
                    if (pt1.sz == 1 || pt2.sz == 1)
                    {
                        cout << "NO" << endl;
                        return;
                    }
                    if (!diag_reachable(t))
                    {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
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