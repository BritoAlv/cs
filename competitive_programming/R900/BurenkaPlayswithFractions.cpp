// Problem: A. Burenka Plays with Fractions
// Contest: Codeforces - Codeforces Round 815 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1720/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: a*d should be equal to c*b
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long min = (a * d <= c * b ? a * d : c * b);
    long long max = (a * d <= c * b ? c * b : a * d);

    if (min == max)
    {
        cout << 0 << '\n';
    }
    else if (min == 0 || max % min == 0)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 2 << '\n';
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
