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

const long long MOD = 1000000007;
const int SIZE = 300001;
long long dp[SIZE];

void init()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < SIZE; i++)
    {
        dp[i] = dp[i - 1];
        dp[i] += 2 * (i - 1) * dp[i - 2];
        dp[i] %= MOD;
    }
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<pi> ocuped;
    fork
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            n--;
        }
        else
        {
            n -= 2;
        }
    }
    cout << dp[n] << endl;
    return;
}

int main()
{
    init();
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