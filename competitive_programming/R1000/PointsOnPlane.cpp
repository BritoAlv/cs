// Problem: B. Points on Plane
// Contest: Codeforces - Educational Codeforces Round 145 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1809/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: ceil( sqrt(n)) -1, a square moved 45 degrees.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

bool condition(long long a, long long n)
{
    return (a * a >= n && (a - 1) * (a - 1) < n);
}

long long sqrt(long long n)
{
    long long start = 1;
    long long end = n;
    while (end - start > 1)
    {
        long long middle = (start + end) / 2;
        if ((__int128)middle * middle < n)
        {
            start = middle + 1;
        }
        else
        {
            end = middle;
        }
    }
    if (condition(start, n))
    {
        return start;
    }
    else
    {
        return end;
    }
}

int test_cases;

void Solve()
{
    long long n;
    cin >> n;
    cout << sqrt(n) - 1 << endl;
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
