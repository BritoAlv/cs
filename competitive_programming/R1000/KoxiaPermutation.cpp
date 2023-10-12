// Problem: B. Koxia and Permutation
// Contest: Codeforces - Good Bye 2022: 2023 is NEAR
// URL: https://codeforces.com/contest/1770/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    cin >> n >> k;
    if (n % 2 == 0)
    {
        for (int i = n; i > n / 2; i--)
        {
            cout << i << wp << n - i + 1 << wp;
        }
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << (n + 1 - i) << wp << i << wp;
        }
        cout << n / 2 + 1 << wp;
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
