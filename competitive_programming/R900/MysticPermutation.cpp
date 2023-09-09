// Problem: B. Mystic Permutation
// Contest: Codeforces - Codeforces Round 798 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1689/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    forn
    {
        cin >> a[i];
        b[i] = i + 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] == a[i])
        {
            int temp = b[i + 1];
            b[i + 1] = b[i];
            b[i] = temp;
        }
    }
    if (n == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        if (b[n - 1] == a[n - 1])
        {
            int temp = b[n - 2];
            b[n - 2] = b[n - 1];
            b[n - 1] = temp;
        }
        forn
        {
            cout << b[i] << ' ';
        }
        cout << endl;
    }

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
