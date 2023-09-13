// Problem: B. 2D Traveling
// Contest: Codeforces - Codeforces Round 896 (Div. 2)
// URL: https://codeforces.com/contest/1869/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: compute distA free city, compute distB free city,
// and take minimal
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

long long get_dist(long long x1, long long y1, long long x2, long long y2)
{
    long long result = 0;
    if (x1 - x2 < 0)
    {
        result += (x2 - x1);
    }
    else
    {
        result += (x1 - x2);
    }

    if (y1 - y2 < 0)
    {
        result += (y2 - y1);
    }
    else
    {
        result += (y1 - y2);
    }
    return result;
}

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

void Solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    long long xs[n + 1];
    long long ys[n + 1];
    int i = 1;
    while (i <= n)
    {
        cin >> xs[i] >> ys[i];
        i++;
    }

    long long mintoA = get_dist(xs[a], ys[a], xs[b], ys[b]);
    long long mintoB = get_dist(xs[a], ys[a], xs[b], ys[b]);

    for (int i = 1; i <= k; i++)
    {
        long long dist1 = get_dist(xs[i], ys[i], xs[a], ys[a]);
        if (dist1 < mintoA)
        {
            mintoA = dist1;
        }
        long long dist2 = get_dist(xs[i], ys[i], xs[b], ys[b]);
        if (dist2 < mintoB)
        {
            mintoB = dist2;
        }
    }

    if (a <= k && b <= k)
    {
        cout << 0 << endl;
    }

    else if (a > k && b > k)
    {
        cout << min(get_dist(xs[a], ys[a], xs[b], ys[b]), mintoA + mintoB) << endl;
    }
    else if (a <= k)
    {
        cout << min(get_dist(xs[a], ys[a], xs[b], ys[b]), mintoB) << endl;
    }
    else
    {
        cout << min(get_dist(xs[a], ys[a], xs[b], ys[b]), mintoA) << endl;
    }

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
