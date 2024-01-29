// Problem: B. A Balanced Problemset?
// Contest: Codeforces - Codeforces Round 921 (Div. 2)
// URL: https://codeforces.com/contest/1925/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
    ull n, x;
    cin >> n >> x;
    set<int, greater<int>> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    for (auto y : divisors)
    {
        // split n as the sum of x numbers all divisible by y.
        if (y * x <= n)
        {
            cout << y << endl;
            return;
        }
    }
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
