// Problem: B. GCD Problem
// Contest: Codeforces - Codeforces Round 761 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1617/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
/*
    a tricky one, at least for me, find a prime that do not divide
    (n-1) and go on, and it can be found because the number can't be
    very large.
*/
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 31, 37, 41, 43, 47};

void Solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << 2 << wp << (n - 3) << wp << 1 << endl;
    }
    else
    {
        int index = 0;
        while ((n - 1) % primes[index] == 0)
        {
            index++;
        }

        cout << primes[index] << wp << (n - 1 - primes[index]) << wp << 1 << endl;
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
