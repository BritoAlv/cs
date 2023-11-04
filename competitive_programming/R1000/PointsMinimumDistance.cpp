// Problem: B. Points and Minimum Distance
// Contest: Codeforces - Educational Codeforces Round 157 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1895/problem/B
// Memory Limit: 512 MB
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
    n *= 2;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long sum = 0;
    for (int i = 1; i < n / 2; i++)
    {
        sum += (a[i] - a[i - 1]);
    }
    for (int i = n / 2; i < n - 1; i++)
    {
        sum += (a[i + 1] - a[i]);
    }
    cout << sum << endl;
    for (int i = 0; i < n / 2; i++)
    {
        cout << a[i] << wp << a[n - 1 - i] << endl;
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
