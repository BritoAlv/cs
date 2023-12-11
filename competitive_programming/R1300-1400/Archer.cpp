// Problem: B. Archer
// Contest: Codeforces - Codeforces Round 185 (Div. 2)
// URL: https://codeforces.com/contest/312/problem/B
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

using namespace std;

void Solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double aa, bb, cc, dd;
    aa = a;
    bb = b;
    cc = c;
    dd = d;

    double P = 1 - (1 - aa / bb) * (1 - cc / dd);
    printf("%0.15f\n", (aa / bb) / P);
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
