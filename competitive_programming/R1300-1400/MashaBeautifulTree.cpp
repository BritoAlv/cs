// Problem: D. Masha and a Beautiful Tree
// Contest: Codeforces - Codeforces Round 826 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1741/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int a[262144];

int solve_recursive(int start, int end, int pow)
{
    if (start == end)
    {
        return 0;
    }
    int middle = (start + end) / 2;
    int l = a[start] > pow;
    if (l == 0)
    {
        for (int i = middle + 1; i <= end; i++)
        {
            a[i] -= (pow);
            if (a[i] <= 0)
            {
                return -1;
            }
        }
    }
    else
    {
        for (int i = start; i <= middle; i++)
        {
            a[i] -= (pow);
            if (a[i] <= 0)
            {
                return -1;
            }
        }
    }
    int A = solve_recursive(start, middle, pow / 2);
    int B = solve_recursive(middle + 1, end, pow / 2);
    if (A == -1 || B == -1)
    {
        return -1;
    }
    else
    {
        return l + A + B;
    }
}

void Solve()
{
    int n;
    cin >> n;
    forn
    {
        cin >> a[i];
    }
    cout << solve_recursive(0, n - 1, n / 2) << endl;
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