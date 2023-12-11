// Problem: A. Little Pony and Expected Maximum
// Contest: Codeforces - Codeforces Round 259 (Div. 1)
// URL: https://codeforces.com/problemset/problem/453/A
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

using namespace std;

void Solve()
{
    int m, n;
    cin >> m >> n;
    double prob[m + 1];
    prob[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        prob[i] = pow((double)i / (double)m, n) - pow((double)(i - 1) / (double)m, n);
    }
    double expected = 0;
    for (int i = 1; i <= m; i++)
    {
        expected += (double)i * (prob[i]);
    }
    printf("%0.9f\n", expected);
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
