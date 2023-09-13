// Problem: B. Odd Grasshopper
// Contest: Codeforces - Codeforces Round 753 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1607/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: after 4 steps you get to the same position.
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
    long long x0, n;
    cin >> x0 >> n;
    long long m = n - n % 4 + 1;
    while (m <= n)
    {
        if (x0 % 2 == 0)
        {
            x0 -= m;
        }
        else
        {
            x0 += m;
        }
        m++;
    }
    cout << x0 << endl;

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
