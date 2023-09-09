// Problem: C. Non-coprime Split
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1872/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: instead of using the cribe for as boolean to know if a number
// is prime, store the smallest prime divisor of the number.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int is_prime[10000001];

void Solve()
{
    int l, r;
    cin >> l >> r;
    if (r == l)
    {
        if (is_prime[l] != l)
        {
            cout << is_prime[l] << ' ' << l - is_prime[l] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        if (l % 2 == 0 && l > 2)
        {
            cout << l / 2 << ' ' << l / 2 << endl;
        }
        else if (r % 2 == 0 && r > 2)
        {
            cout << r / 2 << ' ' << r / 2 << endl;
        }
        else if (l > 2)
        {
            cout << (l + 1) / 2 << ' ' << (l + 1) / 2 << endl;
        }
        else if (r > 4)
        {
            cout << (r - 1) / 2 << ' ' << (r - 1) / 2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return;
}

int main()
{
    is_prime[0] = 0;
    is_prime[1] = 1;
    for (int i = 2; i <= 10000000; i++)
    {
        if (is_prime[i] == 0)
        {
            is_prime[i] = i;
            for (int j = 2 * i; j <= 10000000; j += i)
            {
                if (is_prime[j] == 0)
                {
                    is_prime[j] = i;
                }
            }
        }
    }
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
