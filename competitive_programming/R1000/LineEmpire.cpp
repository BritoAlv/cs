// Problem: C. Line Empire
// Contest: Codeforces - Codeforces Round 782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long p[n + 1];
    long long suffix_sum[n + 2];
    forn
    {
        cin >> p[i + 1];
    }
    p[0] = 0;
    suffix_sum[n + 1] = 0;
    suffix_sum[n] = p[n];
    for (int i = n - 1; i >= 0; i--)
    {
        suffix_sum[i] = p[i] + suffix_sum[i + 1];
    }
    long long answer = -1;
    for (int i = 0; i < n + 1; i++)
    {
        long long candidate = 0;

        candidate += b * (p[i]);
        candidate += a * (p[i]);

        candidate += b * (suffix_sum[i + 1]);
        candidate -= b * (n - i) * p[i];
        if (answer == -1)
        {
            answer = candidate;
        }
        else
        {
            answer = min(answer, candidate);
        }
    }
    cout << answer << endl;
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
