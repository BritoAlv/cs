// Problem: A. Ian and Array Sorting
// Contest: Codeforces - Codeforces Round 865 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1815/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] > a[i])
        {
            a[i + 1] += (a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }
    for (int i = n - 1; i >= 2; i--)
    {
        if (a[i] < a[i - 1])
        {
            a[i - 2] -= (a[i - 1] - a[i]);
            a[i - 1] = a[i];
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
