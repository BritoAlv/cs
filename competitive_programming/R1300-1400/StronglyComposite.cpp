// Problem: C. Strongly Composite
// Contest: Codeforces - Codeforces Round 868 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1823/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

int primes[10000001];

void init()
{
    for (int i = 0; i <= 10000001; i++)
    {
        primes[i] = i;
    }
    for (int i = 2; i <= 10000001; i++)
    {
        if (primes[i] == i)
        {
            for (int j = 2 * i; j <= 10000001; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    map<int, int> p_count;
    forn
    {
        int x = a[i];
        while (x > 1)
        {
            if (p_count.find(primes[x]) == p_count.end())
            {
                p_count[primes[x]] = 0;
            }
            p_count[primes[x]]++;
            x = x / primes[x];
        }
    }
    long long total = 0;
    int rems = 0;
    for (auto x : p_count)
    {
        total += x.second / 2;
        if (x.second % 2 == 1)
        {
            rems++;
        }
    }
    total += rems / 3;
    cout << total << endl;

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
