// Problem: D. Wooden Toy Festival
// Contest: Codeforces - Codeforces Round 878 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1840/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int a[200000];
int n;

int works(int d)
{
    int x1 = a[0] + d;
    forn
    {
        if (a[i] > x1 + d)
        {
            int x2 = a[i] + d;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] > x2 + d)
                {
                    int x3 = a[j] + d;
                    for (int r = j + 1; r < n; r++)
                    {
                        if (a[r] > x3 + d)
                        {
                            return 0;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    return 1;
}

void Solve()
{
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    int ld = 0;
    int gd = 1e9;
    sort(a, a + n);
    while (gd - ld > 1)
    {
        int middle = (ld + gd) / 2;
        if (works(middle))
        {
            gd = middle;
        }
        else
        {
            ld = middle + 1;
        }
    }
    if (works(ld))
    {
        cout << ld << endl;
    }
    else
    {
        cout << gd << endl;
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