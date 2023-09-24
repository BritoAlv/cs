// Problem: B. Grid Reconstruction
// Contest: Codeforces - Codeforces Round 865 (Div. 2)
// URL: https://codeforces.com/contest/1816/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof: IDK why this works sadly
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
        a[i] = 0;
        b[i] = 0;
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (i % 2 == 0)
        {
            a[i] = 2 * n - 2 * i;
            b[i] = 2 * n - 2 * i - n;
            b[n - 1 - i] = 2 * n - 2 * i - 1;
            a[n - 1 - i] = 2 * n - 2 * i - 1 - n;
        }
        else
        {
            b[i] = 2 * n - 2 * i;
            a[i] = 2 * n - 2 * i - n;
            a[n - 1 - i] = 2 * n - 2 * i - 1;
            b[n - 1 - i] = 2 * n - 2 * i - 1 - n;
        }
    }

    forn
    {
        cout << a[i] << wp;
    }
    cout << endl;
    forn
    {
        cout << b[i] << wp;
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