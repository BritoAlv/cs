// Problem: C. Almost All Multiples
// Contest: Codeforces - Codeforces Round 836 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1758/C
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
    int n, x;
    cin >> n >> x;
    int p[n + 1];
    p[1] = x;
    p[n] = 1;
    if (n % x != 0)
    {
        cout << -1 << endl;
        return;
    }

    // this part works.
    for (int i = 2; i < n; i++)
    {
        p[i] = i;
        if (i == x)
        {
            p[i] = n;
        }
    }
    int to_move = x;
    for (int i = x + 1; i < n; i++)
    {
        if (n % i == 0 && i % to_move == 0)
        {
            p[to_move] = p[i];
            p[i] = n;
            to_move = i;
        }
    }
    forn
    {
        cout << p[i + 1] << wp;
    }
    cout << endl;
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