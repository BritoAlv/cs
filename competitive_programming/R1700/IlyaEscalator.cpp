// Problem: D. Ilya and Escalator
// Contest: Codeforces - Codeforces Round 293 (Div. 2)
// URL: https://codeforces.com/problemset/problem/518/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

long double ans_rec(int n, int i, int t, long double p)
{
    if (i == 1)
    {
        return t * pow(p, i) * pow(1 - p, t - i);
    }
    else
    {
        long double A = t - i + 1;
        A /= (long double)i;
        A *= p;
        A /= (1 - p);
        return ans_rec(n, i - 1, t, p) * A;
    }
}

long double ans_rec2(int n, int j, int t, long double p)
{
    if (j == n)
    {
        return 1;
    }
    else
    {
        long double ans = ans_rec2(n, j - 1, t, p);
        ans *= (long double)(1 - p);
        ans *= (long double)(j - 1);
        ans /= (long double)(j - n);
        return ans;
    }
}

long double P(int n, int i, int t, long double p)
{
    if (i >= t + 1)
    {
        return 0;
    }
    else
    {
        if (i < n)
        {
            return ans_rec(n, i, t, p);
        }
        else
        {
            long double sum = 0;
            for (int j = n; j <= t; j++)
            {
                sum += ans_rec2(n, j, t, p);
            }
            return sum * pow(p, n);
        }
    }
}

void Solve()
{
    int n;
    long double p;
    int t;
    cin >> n >> p >> t;
    if (p == 1)
    {
        cout << n << endl;
        return;
    }
    if (p == 0)
    {
        cout << 0 << endl;
        return;
    }
    long double expected = 0;
    for (int i = 1; i <= n; i++)
    {
        expected += i * P(n, i, t, p);
    }
    printf("%Lf\n", expected);
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}