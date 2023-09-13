// Problem: C. Two Arrays
// Contest: Codeforces - Technocup 2022 - Elimination Round 2
// URL: https://codeforces.com/problemset/problem/1584/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: sort and sort
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
    int b[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        if (!(a[i] + 1 == b[i] || a[i] - b[i] == 0))
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
