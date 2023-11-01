// Problem: A. Morning
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/contest/1883/problem/A
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
    int n = 5;
    int a[n];
    a[0] = 1;
    for (int i = 1; i < 5; i++)
    {
        char t;
        cin >> t;
        if (t == '0')
        {
            a[i] = 10;
        }
        else
        {
            a[i] = (int)(t - '0');
        }
    }
    int sum = 0;
    for (int i = 1; i < 5; i++)
    {
        sum += abs(a[i] - a[i - 1]) + 1;
    }
    cout << sum << endl;

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
