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

#define MAX_SIZE 100001

int dp[MAX_SIZE][20];

int get_first(int start_index, int row_index, int value, int M)
{
    if (start_index >= M)
    {
        return -1;
    }
    for (int i = row_index; i >= 0; i--)
    {
        if (dp[start_index][i] > value)
        {
            int next_index = start_index + (1 << i);
            if (next_index >= M)
            {
                return -1;
            }
            return get_first(next_index, i, value, M);
        }
    }
    return start_index;
}

void Solve()
{
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
        cin >> dp[i][0];
    }
    for (int i = 1; i <= two_pow; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[j][i] = min(dp[j][i - 1], dp[min(M - 1, j + (1 << (i - 1)))][i - 1]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        int start = queries[i];
        int first_index = get_first(0, two_pow, start, M);
        while (first_index >= 0)
        {
            start %= dp[first_index][0];
            if (start == 0)
            {
                break;
            }
            first_index = get_first(first_index + 1, two_pow, start, M);
        }
        cout << start << wp;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}