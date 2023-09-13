// Problem: B. Special Permutation
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1612/B
// Memory Limit: 512 MB why so much
// Time Limit: 2000 ms
// Math Proof: implementation
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
    int n, a, b;
    cin >> n >> a >> b;
    int count1 = n - b;
    if (a > b)
    {
        count1--;
    }
    int count2 = a - 1;
    if (b < a)
    {
        count2--;
    }
    if (count1 < n / 2 && count2 < n / 2)
    {
        cout << a << ' ';
        for (int i = n; i >= (b + 1); i--)
        {
            if (i == a)
            {
                continue;
            }
            cout << i << wp;
        }

        for (int i = (a + 1); i <= (b - 1); i++)
        {
            cout << i << wp;
        }

        for (int i = (a - 1); i >= 1; i--)
        {
            if (i == b)
            {
                continue;
            }
            cout << i << wp;
        }
        cout << b << ' ' << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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
