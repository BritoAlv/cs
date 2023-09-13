// Problem: A. PizzaForces
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1555/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: PizzaForces, diophantine equation.
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
    long long n;
    cin >> n;
    long long min = 5 * n / 2;
    if (min < 15)
    {
        min = 15;
    }
    if (min % 5 == 0)
    {
        cout << min << endl;
    }
    else
    {
        cout << min - (min % 5) + 5 << endl;
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
