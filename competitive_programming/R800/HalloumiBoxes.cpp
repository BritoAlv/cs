// Problem: A. Halloumi Boxes
// Contest: Codeforces - Codeforces Round 912 (Div. 2)
// URL: https://codeforces.com/contest/1903/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n, k;
    cin >> n >> k;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    if (k >= 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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
