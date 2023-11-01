// Problem: B. Consecutive Points Segment
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/B
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

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > 1)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                a[j]++;
            }
            for (int j = i; j < n; j++)
            {
                if (a[j] - a[j - 1] > 1)
                {
                    a[j]--;
                }
            }
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > 1)
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
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
