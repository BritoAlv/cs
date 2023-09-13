// Problem: C. Fill in the Matrix
// Contest: Codeforces - Codeforces Round 896 (Div. 2)
// URL: https://codeforces.com/contest/1869/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: notice that in almost all cases answer is
// min(m ,n+1), to do so print the permutation ith shift to
// the right, and ensure it is a permutation.
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int min(int a, int b)
{
    return a < b ? a : b;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    if (m > 1)
    {
        cout << min(m, n + 1) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    int to_print = n;
    if (m == 1)
    {
        while (to_print > 0)
        {
            cout << 0 << endl;
            to_print--;
        }
    }
    else if (n == 1)
    {
        for (int i = 0; i < m; i++)
        {
            cout << i << wp;
        }
        cout << endl;
    }
    else
    {
        if (n >= m)
        {
            while (to_print > m)
            {
                for (int i = 0; i < m; i++)
                {
                    cout << i << wp;
                }
                cout << endl;
                to_print--;
            }
            int start = 0;
            while (to_print > 0)
            {
                if (to_print == 1 && n > 1)
                {
                    for (int i = 0; i < m; i++)
                    {
                        cout << i << wp;
                    }
                    cout << endl;
                }
                else
                {
                    for (int i = 0; i < m; i++)
                    {
                        cout << (start + i) % m << wp;
                    }
                    start++;
                    cout << endl;
                }
                to_print--;
            }
        }
        else
        {
            int start = 0;
            while (to_print > 0)
            {
                for (int i = 0; i < m; i++)
                {
                    if (i <= n)
                    {
                        cout << (start + i) % (n + 1) << wp;
                    }
                    else
                    {
                        cout << i << wp;
                    }
                }
                cout << endl;
                start++;
                to_print--;
            }
        }
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
