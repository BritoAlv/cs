// Problem: A. 2023
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/A
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
#define ull unsigned long long
using namespace std;

void Solve()
{
    int n, k;
    cin >> n >> k;
    int product = 1;
    int a[n];
    forn
    {
        cin >> a[i];
        product *= a[i];
        if (product > 2023)
        {
            product = 0;
        }
    }
    if (product == 0 || 2023 % product != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++)
        {
            cout << 1 << wp;
        }
        cout << 2023 / product << endl;
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
