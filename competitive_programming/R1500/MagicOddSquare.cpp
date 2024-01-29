// Problem: C. Magic Odd Square
// Contest: Codeforces - Educational Codeforces Round 16
// URL: https://codeforces.com/contest/710/problem/C
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
    int n;
    cin >> n;
    int odd_t = 1;
    int even_t = 2;
    vector<vector<int>> A;
    forn
    {
        A.pb(vector<int>(n));
    }
    int m = n;
    forn
    {
        if (i < n / 2)
        {
            form
            {
                if ((j < n / 2 && j <= i) || (j > n / 2 && n - 1 - j <= i))
                {
                    A[i][j] = even_t;
                    even_t += 2;
                }
                else
                {
                    A[i][j] = odd_t;
                    odd_t += 2;
                }
            }
        }
        else if (i == n / 2)
        {
            form
            {
                A[i][j] = odd_t;
                odd_t += 2;
            }
        }
        else
        {
            form
            {
                if ((j < n / 2 && j <= n - 1 - i) || (j > n / 2 && n - 1 - j <= n - 1 - i))
                {
                    A[i][j] = even_t;
                    even_t += 2;
                }
                else
                {
                    A[i][j] = odd_t;
                    odd_t += 2;
                }
            }
        }
        form
        {
            cout << A[i][j] << wp;
        }
        cout << endl;
    }
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
