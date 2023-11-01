// Problem: C. Flower City Fence
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/C
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
    vector<int> b(n, 0);

    forn
    {
        cin >> a[i];
        if (1 <= a[i] && a[i] <= n)
        {
            b[a[i] - 1]++;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        b[i] += b[i + 1];
    }
    forn
    {
        if (a[i] != b[i])
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
