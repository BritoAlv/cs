// Problem: C. Hossam and Trainees
// Contest: Codeforces - Codeforces Round 837 (Div. 2)
// URL: https://codeforces.com/contest/1771/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

vector<int> prims;

int primes[100000];

void init()
{
    int ubound = sqrt(1e9) + 1;
    for (int i = 0; i <= ubound; i++)
    {
        primes[i] = i;
    }
    for (int i = 2; i <= ubound; i++)
    {
        if (primes[i] == i)
        {
            for (int j = 2 * i; j <= ubound; j += i)
            {
                if (primes[j] == j)
                {
                    primes[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= ubound; i++)
    {
        if (primes[i] == i)
        {
            prims.pb(i);
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
    sort(a, a + n);
    for (auto x : prims)
    {
        int count1 = 0;
        forn
        {
            if (a[i] % x == 0)
            {
                count1 += 1;
                if (count1 >= 2)
                {
                    cout << "YES" << endl;
                    return;
                }
                while (a[i] % x == 0)
                {
                    a[i] /= x;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] && a[i] > 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
