// Problem: A. Increasing Sequence
// Contest: Codeforces - Codeforces Round 899 (Div. 2)
// URL: https://codeforces.com/contest/1882/problem/0
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
    int n;
    cin >> n;
    int shift = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t == i + shift)
        {
            shift++;
        }
    }
    cout << n + shift << endl;
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
