// Problem: D. Ice Cream Balls
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: Binary Search Is Tanking
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
    long long start = 1;
    long long end = 1e10;
    while (end - start > 1)
    {
        long long middle = (start + end) / 2;
        if (middle * (middle - 1) > 2 * n)
        {
            end = middle - 1;
        }
        else if (middle * (middle - 1) == 2 * n)
        {
            end = middle;
        }
        else
        {
            start = middle;
        }
    }
    long long answer = end;
    if (end * (end - 1) > 2 * n)
    {
        answer = end - 1;
    }
    cout << n - (answer * (answer - 1)) / 2 + answer << endl;
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
