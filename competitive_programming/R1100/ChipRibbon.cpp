// Problem: B. Chip and Ribbon
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1901/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int i = 0; i < m; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    long long ops = 0;
    forn
    {
        cin >> a[i];
        if (i == 0)
        {
            ops += a[i] - 1;
        }
        else
        {
            if (a[i] >= a[i - 1] && a[i - 1] > 0)
            {
                ops += a[i] - a[i - 1];
            }
            else if (a[i - 1] == 0)
            {
                ops++;
                ops += a[i] - 1;
            }
        }
    }
    cout << ops << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}