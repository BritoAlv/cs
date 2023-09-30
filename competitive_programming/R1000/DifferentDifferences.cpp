// Problem: C. Different Differences
// Contest: Codeforces - Codeforces Round 839 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1772/C
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

int test_cases;

void Solve()
{
    int n, k;
    cin >> k >> n;
    int a[k];
    for (int i = 0; i < k; i++)
    {
        a[i] = i + 1;
    }
    int start = 2;
    int shift = 1;
    while ((a[k - 1] + shift <= n) && start < k)
    {
        for (int j = start; j < k; j++)
        {
            a[j] += shift;
        }
        start++;
        shift++;
    }
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << wp;
    }
    cout << endl;

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
