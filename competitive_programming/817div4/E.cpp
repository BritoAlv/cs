// Problem: E. Counting Rectangles
// Contest: Codeforces - Codeforces Round 817 (Div. 4)
// URL: https://codeforces.com/contest/1722/problem/E
// Memory Limit: 256 MB
// Time Limit: 6000 ms
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

vector<vector<long long>> board(1001, vector<long long>(1001));

long long query_solve()
{
    long long hs, ws, hb, wb;
    cin >> hs >> ws >> hb >> wb;
    if (hb == hs + 1 or wb == ws + 1)
    {
        return 0;
    }
    else
    {
        hs++;
        hb--;
        ws++;
        wb--;
        return (board[hb][wb] - board[hb][ws - 1]) - (board[hs - 1][wb] - board[hs - 1][ws - 1]);
    }
}

void Solve()
{
    board = vector<vector<long long>>(1001, vector<long long>(1001, 0));
    int n, q;
    cin >> n >> q;
    forn
    {
        long long a, b;
        cin >> a >> b;
        board[a][b] += a * b;
    }
    for (int a = 1; a < 1001; a++)
    {
        for (int b = 1; b < 1001; b++)
        {
            board[a][b] += board[a][b - 1];
        }
    }
    for (int b = 1; b < 1001; b++)
    {
        for (int a = 1; a < 1001; a++)
        {
            board[a][b] += board[a - 1][b];
        }
    }
    while (q > 0)
    {
        q--;
        cout << query_solve() << endl;
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