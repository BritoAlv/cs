// Problem: B. Two Divisors
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int primes[40000];
vector<int> primess;
map<int, int> s_a;
void init()
{
    for (int i = 0; i < 40000; i++)
    {
        primes[i] = i;
    }
    for (int i = 2; i < 40000; i += 2)
    {
        if (primes[i] == i)
        {
            for (int j = 2 * i; j < 40000; j += i)
            {
                primes[j] = i;
            }
        }
    }
    for (int i = 2; i < 40000; i++)
    {
        if (primes[i] == i)
        {
            primess.pb(i);
        }
    }
}

int mcd(int a, int b)
{
    if (a > b)
    {
        return mcd(b, a);
    }
    else if (a == b)
    {
        return a;
    }
    else
    {
        // a < b
        if (b % a == 0)
        {
            return a;
        }
        else
        {
            return mcd(b % a, a);
        }
    }
}

void Solve()
{
    long long a, b;
    cin >> a >> b;
    long long result = a;
    result *= b;
    result /= mcd(a, b);
    if (result != b)
    {
        cout << result << endl;
    }
    else
    {
        if (s_a.find(b) != s_a.end())
        {
            cout << result * s_a[b] << endl;
        }
        else
        {
            for (auto i : primess)
            {
                if (b % i == 0)
                {
                    s_a[b] = i;
                    cout << result * i << endl;
                    return;
                }
            }
        }
    }
    return;
}

int main()
{
    init();
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
