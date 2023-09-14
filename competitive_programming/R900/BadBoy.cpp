// Problem: B. Bad Boy
// Contest: Codeforces - Codeforces Round 726 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1537/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: corners ...
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int dist(int x0, int y0, int x, int y)
{
    return abs(x0 - x) + abs(y0 - y);
}

void Solve()
{
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    int distance1 = dist(i, j, 1, 1) + dist(i, j, n, m);
    int distance2 = dist(i, j, 1, m) + dist(i, j, n, 1);

    if (distance1 > distance2)
    {
        cout << 1 << wp << 1 << wp << n << wp << m << endl;
    }
    else
    {
        cout << 1 << wp << m << wp << n << wp << 1 << endl;
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
