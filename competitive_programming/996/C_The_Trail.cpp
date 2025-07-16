// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

template <typename K, typename V> void print(const std::map<K, V> &m)
{
    for (const auto &[key, value] : m)
    {
        std::cout << key << ": " << value << "\n";
    }
}

int test_cases;
using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<char> moves(n + m - 2);
    fori(0, n + m - 3)
    {
        cin >> moves[i];
    }
    vector<vl> board(n, vl(m));
    vl sum_rows(n);
    vl sum_cols(m);
    fori(0, n - 1)
    {
        forj(0, m - 1)
        {
            cin >> board[i][j];
            sum_rows[i] += board[i][j];
            sum_cols[j] += board[i][j];
        }
    }

    pl cur_pos = {0, 0};
    for (auto z : moves)
    {
        pl next_pos;
        if (z == 'D')
        {
            next_pos = {cur_pos.first + 1, cur_pos.second};
            board[cur_pos.first][cur_pos.second] = -sum_rows[cur_pos.first];
        }
        else
        {
            next_pos = {cur_pos.first, cur_pos.second + 1};
            board[cur_pos.first][cur_pos.second] = -sum_cols[cur_pos.second];
        }
        sum_rows[cur_pos.first] += board[cur_pos.first][cur_pos.second];
        sum_cols[cur_pos.second] += board[cur_pos.first][cur_pos.second];
        cur_pos = next_pos;
    }
    board[n - 1][m - 1] = -sum_rows[n - 1];
    fori(0, n - 1)
    {
        print(board[i]);
    }
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
