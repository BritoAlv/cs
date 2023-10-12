// Problem: A. Alfajores
// Contest: Codeforces - 2023 Argentinian Programming Tournament (TAP)
// URL: https://codeforces.com/gym/104603/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int get_first(int start_index, int row_index, int value, int M, int dp[20][10001])
{
    if (start_index >= M)
    {
        return -1;
    }
    for (int i = row_index; i >= 0; i--)
    {
        if (dp[i][start_index] > value)
        {
            int next_index = start_index + (1 << i);
            if (next_index >= M)
            {
                return -1;
            }
            return get_first(next_index, i, value, M, dp);
        }
    }
    return start_index;
}

void Solve()
{
    int dp[20][10001];
    int N, M;
    cin >> N >> M;
    int queries[N];
    for (int i = 0; i < N; i++)
    {
        cin >> queries[i];
    }

    int two_pow = 0;
    while (M >= (1 << two_pow))
    {
        two_pow++;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> dp[0][i];
    }
    for (int i = 1; i <= two_pow; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][min(M - 1, j + (1 << (i - 1)))]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        int start = queries[i];
        int first_index = get_first(0, two_pow, start, M, dp);
        while (first_index >= 0)
        {
            start -= (start / dp[0][first_index]) * dp[0][first_index];
            first_index = get_first(first_index + 1, two_pow, start, M, dp);
        }
        queries[i] = start;
    }
    for (auto x : queries)
    {
        cout << x << wp;
    }

    return;
}

int main()
{
    Solve();
    return 0;
}