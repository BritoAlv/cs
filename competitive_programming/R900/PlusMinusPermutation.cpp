// Problem: D. Plus Minus Permutation
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1872/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: count number divisible by x, by y, and by both
// and use inclusion-exclusion
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int mcd(int x, int y)
{
    if (x == y)
    {
        return x;
    }
    if (x < y)
    {
        if (y % x == 0)
        {
            return x;
        }
        else
        {
            return mcd(y % x, x);
        }
    }
    if (x > y)
    {
        if (x % y == 0)
        {
            return y;
        }
        else
        {
            return mcd(x % y, y);
        }
    }
}

void Solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    long long pointer1 = n;
    long long pointer2 = 1;
    long long sum = 0;

    // only I have to count the number of
    // values that are divisible by x, not
    // by y and <= n.

    // divisible by x less equal n
    // = floor(n/x)
    // A+B B are divisible by x and y so by mcm(x,y)
    long long first = x;
    first *= y;
    first /= mcd(x, y);

    long long count3 = n / first;

    long long count1 = n / x - count3;
    long long count2 = n / y - count3;

    sum -= (count2 * (count2 + 1)) / 2;
    sum += count1 * n;
    sum -= ((count1 - 1) * (count1)) / 2;

    cout << sum << endl;
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
