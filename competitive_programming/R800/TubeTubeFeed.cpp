// Problem: A. TubeTube Feed
// Contest: Codeforces - Codeforces Round 867 (Div. 3)
// URL: https://codeforces.com/contest/1822/problem/A
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

void Solve()
{
    int n, t;
    cin >> n >> t;
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    int index_max = -2;
    forn
    {
        if (i + a[i] <= t)
        {
            if (index_max == -2 || b[index_max] < b[i])
            {
                index_max = i;
            }
        }
    }
    cout << index_max + 1 << endl;
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
