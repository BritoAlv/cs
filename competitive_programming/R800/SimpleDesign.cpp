// Problem: A. Simple Design
// Contest: Codeforces - Codeforces Round 904 (Div. 2)
// URL: https://codeforces.com/contest/1884/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: why k < 20 ?
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

bool prop(int a, int k)
{
    int digits = 0;
    while (a > 0)
    {
        digits += (a % 10);
        a /= 10;
    }
    return (digits % k == 0);
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 20; i++)
    {
        if (prop(n + i, k))
        {
            cout << n + i << endl;
            return;
        }
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
