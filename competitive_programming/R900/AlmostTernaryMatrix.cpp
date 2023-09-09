// Problem: B. Almost Ternary Matrix
// Contest: Codeforces - Codeforces Round 804 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1699/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: you have to find it for yourself, in this one I found a bigger
// one and every subboard of it works as long as the cuts are even,
// luckily I found it but ...
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n, m;
    cin >> n >> m;
    int start = 0;
    int end = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 4 == 0 || i % 4 == 3)
        {
            start = 0;
            end = 1;
        }
        else
        {
            start = 1;
            end = 0;
        }
        for (int j = 0; j < m; j++)
        {
            if (j % 4 == 0 || j % 4 == 3)
            {
                cout << start << ' ';
            }
            else
            {
                cout << end << ' ';
            }
        }
        cout << endl;
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
