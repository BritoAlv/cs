// Problem: C. Raspberries
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1883/C
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
    int n, k;
    cin >> n >> k;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int candidate = k;
    int even_count = 0;
    forn
    {
        if (a[i] % 2 == 0)
        {
            even_count++;
        }
        if (a[i] % k == 0)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            candidate = min(candidate, k - (a[i] % k));
        }
    }
    if (k == 4 && even_count >= 2)
    {
        candidate = 0;
    }
    if (k == 4 && n - even_count >= 2)
    {
        candidate = min(candidate, 2);
    }
    if (k == 4 && even_count >= 1 && n - even_count >= 1)
    {
        candidate = min(candidate, 1);
    }
    cout << candidate << endl;

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
