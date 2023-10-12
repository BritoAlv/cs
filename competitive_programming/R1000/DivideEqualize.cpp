// Problem: D. Divide and Equalize
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/contest/1881/problem/D
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

int primes[1000001];

void init()
{

    for (int i = 2; i < 1000001; i++)
    {
        primes[i] = i;
    }
    for (int i = 2; i < 1000001; i++)
    {
        if (primes[i] == i)
        {
            for (int j = 2 * i; j < 1000001; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
    return;
}

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    unordered_set<int> primes_present;
    forn
    {
        cin >> a[i];
        int start = a[i];
        while (start > 1)
        {
            primes_present.insert(primes[start]);
            if (primes[start] == start)
            {
                break;
            }
            else
            {
                start /= primes[start];
            }
        }
    }
    for (auto x : primes_present)
    {
        int exp_sum = 0;
        forn
        {
            if (a[i] % x == 0)
            {
                while (a[i] % x == 0)
                {
                    exp_sum++;
                    a[i] = a[i] / x;
                }
            }
        }
        if (exp_sum % n != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

    return;
}

int main()
{
    init();
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
