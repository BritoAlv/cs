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

int mcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    if (a > b)
    {
        return mcd(b, a);
    }
    if (b % a == 0)
    {
        return a;
    }
    else
    {
        return mcd(a, b % a);
    }
}

void Solve()
{
    vector<int> mapp2 = {2, 5, 17, 31};
    map<char, int> mappp;
    int sum = 2 + 5 + 17 + 31;
    mappp['r'] = 0;
    mappp['w'] = 1;
    mappp['b'] = 2;
    mappp['g'] = 3;
    int n, m;
    cin >> n >> m;
    int mcdd = mcd(n, m);
    vector<vector<int>> board(n, vector<int>(m));
    forn
    {
        form
        {
            char t;
            cin >> t;
            board[i][j] = mapp2[mappp[t]];
        }
    }
    vector<int> mapp(2 * mcdd);
    for (int len1 = -mcdd; len1 < mcdd; len1++)
    {
        for (int r = 0; r < mcdd; r++)
        {
            if (abs(len1 + r) % mcdd == 0)
            {
                mapp[len1 + mcdd] = r;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != j)
            {
                vector<int> lens(2);
                lens[0] = (j - i + 1);
                lens[1] = (m - j + i + 1);
                vector<unordered_set<int>> q(sum);
                for (int z = 0; z < n; z++)
                {
                    if (board[z][i] != board[z][j])
                    {
                        int m = mapp[(lens[0] - z - 1) % mcdd + mcdd];
                        int p = sum - board[z][i] - board[z][j];
                        if (q[p].find(m) != q[p].end())
                        {
                            cout << "possible" << endl;
                            return;
                        }
                        m = mapp[(lens[1] - z - 1) % mcdd + mcdd];
                        p = sum - board[z][i] - board[z][j];
                        if (q[p].find(m) != q[p].end())
                        {
                            cout << "possible" << endl;
                            return;
                        }
                        q[board[z][i] + board[z][j]].insert(z % mcdd);
                    }
                }
            }
        }
    }
    cout << "impossible" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}