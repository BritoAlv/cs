// Problem: D. Beauty of the mountains
// Contest: Codeforces - Codeforces Round 955 (Div. 2, with prizes from NEAR!)
// URL: https://codeforces.com/contest/1982/problem/D
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

int mcd(int a, int b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    return mcd(b, a % b);
}

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board1(n, vector<int>(m));
    vector<vector<int>> board2(n, vector<int>(m));
    long long sum1 = 0;
    long long sum2 = 0;
    forn
    {
        form
        {
            cin >> board1[i][j];
        }
    }
    forn
    {
        form
        {
            char x;
            cin >> x;
            board2[i][j] = (int)(x - '0');
            if (board2[i][j])
            {
                sum1 += board1[i][j];
            }
            else
            {
                sum2 += board1[i][j];
            }
        }
    }
    for (int a = 0; a < n; a++)
    {
        for (int b = 1; b < m; b++)
        {
            board2[a][b] += board2[a][b - 1];
        }
    }
    for (int b = 0; b < m; b++)
    {
        for (int a = 1; a < n; a++)
        {
            board2[a][b] += board2[a - 1][b];
        }
    }
    vector<int> vals;
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = 0; j <= m - k; j++)
        {
            int hb = i + k - 1;
            int wb = j + k - 1;
            int hs = i;
            int ws = j;
            int sum = board2[hb][wb];
            if (ws - 1 >= 0)
                sum -= board2[hb][ws - 1];
            if (hs - 1 >= 0)
                sum -= board2[hs - 1][wb];
            if (ws - 1 >= 0 && hs - 1 >= 0)
                sum += board2[hs - 1][ws - 1];
            int change = abs(k * k - 2 * sum);
            if (change > 0)
                vals.pb(change);
        }
    }
    long long dif = abs(sum1 - sum2);
    if (vals.sz == 0)
        cout << (dif == 0 ? "YES" : "NO") << endl;
    else
    {
        int mcdd = vals[0];
        for (auto x : vals)
        {
            mcdd = mcd(mcdd, x);
        }
        cout << (dif % mcdd == 0 ? "YES" : "NO") << endl;
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
