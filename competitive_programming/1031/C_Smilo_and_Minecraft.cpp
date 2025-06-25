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
vector<vector<char>> board;

vector<vector<int>> psa;

int n, m, k;

int count_gold_boom(int i, int j)
{
    int c1 = max(1, j - k + 1);
    int c2 = min(j + k - 1, m);
    int r1 = max(1, i - k + 1);
    int r2 = min(n, i + k - 1);
    int total = psa[r2][c2] - psa[r2][c1 - 1] - psa[r1 - 1][c2] + psa[r1 - 1][c1 - 1];
    return total;
}

void Solve()
{
    cin >> n >> m >> k;
    board.clear();
    int best = 0;
    int total_gold = 0;
    int R = n;
    int C = m;
    psa = vector<vector<int>>(R + 1, vector<int>(C + 1));
    fori(0, n - 1)
    {
        vector<char> line(m);
        fori(0, m - 1)
        {
            cin >> line[i];
            total_gold += (line[i] == 'g');
        }
        board.push_back(line);
    }
    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
        {
            psa[r][c] = psa[r - 1][c] + psa[r][c - 1] + (board[r - 1][c - 1] == 'g') - psa[r-1][c-1];
        }
    }

    fori(0, n - 1)
    {
        forj(0, m - 1)
        {
            if (board[i][j] == '.')
            {
                int obtained = total_gold - count_gold_boom(i + 1, j + 1);
                //cout << i << wp << j << wp << obtained << endl;
                best = max(best, obtained);
            }
        }
    }
    cout << best << endl;
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