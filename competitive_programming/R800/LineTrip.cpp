// Problem: A. Line Trip
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1901/problem/A
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
    int n, x;
    cin >> n >> x;
    int max_dif = 0;
    int last = 0;
    forn
    {
        int a;
        cin >> a;
        if (i != n - 1)
        {
            max_dif = max(max_dif, a - last);
            last = a;
        }
        else
        {
            max_dif = max(max_dif, a - last);
            max_dif = max(max_dif, 2 * (x - a));
        }
    }
    cout << max_dif << endl;
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
