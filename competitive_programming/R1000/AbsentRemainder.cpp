// Problem: B. Absent Remainder
// Contest: Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1613/problem/B
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

void Solve()
{
    int n;
    cin >> n;
    int minn_index = 0;
    int a[n];
    forn
    {
        cin >> a[i];
        if (a[i] < a[minn_index])
        {
            minn_index = i;
        }
    }
    int counter = 0;
    for (int i = 0; i < n && counter < n / 2; i++)
    {
        if (a[i] != a[minn_index])
        {
            cout << a[i] << wp << a[minn_index] << endl;
            counter++;
        }
    }
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
