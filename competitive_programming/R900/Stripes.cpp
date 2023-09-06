// Problem: C. Stripes
// Contest: Codeforces - Codeforces Round 827 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1742/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: got WA due to not read well the statment
// of the problem it says that rows will be painted red
// and columns will be painted blue.
// find a red row or a blue column but if the problem gets misunderstood thn this case
// is for destroy your solution:
// BBBBBBBB
// RRBBRRRR
// BBBBBBBB
// RBBBRBRB
// RBBBRBRR
// RBBBRBRR
// RRRRRRRR
// RBBBBBRB

// sample cases are never enough.
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    vector<vector<char>> board;
    for (int i = 0; i < 8; i++)
    {
        vector<char> row;
        for (int j = 0; j < 8; j++)
        {
            char t;
            cin >> t;
            row.push_back(t);
        }
        board.push_back(row);
    }
    int iter = 0;
    while (iter < 8)
    {
        if (board[iter][0] == 'R')
        {
            bool is_fine = true;
            for (int j = 1; j < 8; j++)
            {
                if (board[iter][j] != 'R')
                {
                    is_fine = false;
                    break;
                }
            }
            if (is_fine)
            {
                cout << 'R' << '\n';
                return;
            }
        }

        if (board[0][iter] == 'B')
        {

            bool is_fine = true;
            for (int j = 1; j < 8; j++)
            {
                if (board[j][iter] != 'B')
                {
                    is_fine = false;
                    break;
                }
            }
            if (is_fine)
            {
                cout << 'B' << '\n';
                return;
            }
        }
        iter++;
    }
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
