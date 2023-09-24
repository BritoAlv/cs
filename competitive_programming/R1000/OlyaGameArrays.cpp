// Problem: B. Olya and Game with Arrays
// Contest: Codeforces - Codeforces Round 892 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1859/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: implement it take second smallest.
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
    int n;
    cin >> n;
    int a[2 * n];
    int k = 0;
    while (k < n)
    {
        int m;
        cin >> m;
        int min1 = 1000000001;
        int min2 = 1000000001;
        while (m > 0)
        {
            int t;
            cin >> t;
            if (t < min1)
            {
                min2 = min1;
                min1 = t;
            }
            else if (t < min2)
            {
                min2 = t;
            }
            m--;
        }

        a[k] = min1;
        a[n + k] = min2;
        k++;
    }

    long long sum = 0;
    int min1 = a[n];
    int min2 = a[0];
    forn
    {
        sum += a[n + i];
        if (a[n + i] < min1)
        {
            min1 = a[n + i];
        }
        if (a[i] < min2)
        {
            min2 = a[i];
        }
    }

    sum -= min1;
    sum += min2;

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
