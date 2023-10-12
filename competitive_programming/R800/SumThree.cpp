// Problem: A. Sum of Three
// Contest: Codeforces - Educational Codeforces Round 156 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1886/problem/0
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    if (n <= 6 || n == 9)
    {
        cout << "NO" << endl;
    }
    else if (n % 3 != 0)
    {
        cout << "YES" << endl;
        cout << 1 << wp << 2 << wp << (n - 3) << endl;
    }
    else
    {
        if (n % 3 == 0)
        {
            cout << "YES" << endl;
            cout << 1 << wp << 4 << wp << (n - 5) << endl;
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
