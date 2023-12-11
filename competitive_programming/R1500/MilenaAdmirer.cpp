// Problem: B. Milena and Admirer
// Contest: Codeforces - Codeforces Round 910 (Div. 2)
// URL: https://codeforces.com/contest/1898/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    long long ops = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[i - 1])
        {
            // split a[i-1] in parts until holds.
            // bigger number of the part is ceil(a[i-1] / x)
            // where x is the number of parts.
            int x = a[i - 1] / a[i];
            if (a[i - 1] % a[i] != 0)
            {
                x++;
            }
            a[i - 1] /= x;
            ops += (x - 1);
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