// Problem: B. Also Try Minecraft
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1709/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: implementation, need long long and also use prefix sums twice,
// implementing this requires patience
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

long long min(long a, long b)
{
    return a < b ? a : b;
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    long long cl[n + 1];
    forn
    {
        cin >> cl[i + 1];
    }

    long long pdif[n - 1];
    long long ndif[n - 1];
    ndif[n - 2] = -min(0, cl[n - 1] - cl[n]);
    pdif[0] = -min(0, cl[2] - cl[1]);
    for (int i = 3; i <= n; i++)
    {
        pdif[i - 2] = pdif[i - 3] - min(0, cl[i] - cl[i - 1]);
    }
    for (int i = n - 2; i >= 1; i--)
    {
        ndif[i - 1] = ndif[i] - min(0, cl[i] - cl[i + 1]);
    }
    while (m > 0)
    {
        int s, e;
        cin >> s >> e;
        if (s == e)
        {
        }
        else if (s < e)
        {
            cout << pdif[e - 2] - (s == 1 ? 0 : pdif[s - 2]) << endl;
        }
        else
        {
            cout << ndif[e - 1] - (s == n ? 0 : ndif[s - 1]) << endl;
        }
        m--;
    }

    return;
}

int main()
{

    Solve();

    return 0;
}