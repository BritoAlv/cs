// Problem: B. Not Dividing
// Contest: Codeforces - Codeforces Round 856 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1794/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: add one to the ones, and add one to the wrong positiions.

#include <bits/stdc++.h>

using namespace std;

int test_cases;

void Solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            a[i]++;
        }
        if (i >= 1)
        {
            if (a[i] % a[i - 1] == 0)
            {
                a[i]++;
            }
        }
        cout << a[i] << ' ';
    }
    cout << '\n';

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
