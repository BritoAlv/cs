// Problem: B. Summation Game
// Contest: Codeforces - Codeforces Round 919 (Div. 2)
// URL: https://codeforces.com/contest/1920/problem/B
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
#define pb push_back
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long psum[n];
    long long ssum[n];
    psum[0] = a[0];
    ssum[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        psum[i] = psum[i - 1] + a[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ssum[i] = ssum[i + 1] + a[i];
    }
    long long max_ans = psum[n - 1] - 2 * ssum[n - x];
    for (int i = 0; i < k; i++)
    {
        long long result = psum[n - 1];
        result -= psum[i];
        if (max(i + 1, n - x) <= n - 1)
        {
            result -= 2 * ssum[max(i + 1, n - x)];
        }
        max_ans = max(max_ans, result);
    }

    for (int i = n - 1; i > n - 1 - k; i--)
    {
        long long result = psum[n - 1];
        result -= ssum[i];
        // left part from [0, i-1]
        result -= 2 * (ssum[max(0, i - x)] - ssum[i]);
        max_ans = max(max_ans, result);
    }
    cout << max_ans << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
