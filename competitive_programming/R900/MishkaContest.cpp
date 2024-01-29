// Problem: A. Mishka and Contest
// Contest: Codeforces - Codeforces Round 490 (Div. 3)
// URL: https://codeforces.com/contest/999/problem/A
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
    int a[n];
    forn
    {
        cin >> a[i];
    }
    int i = 0;
    int ans = 0;
    for (; i < n; i++)
    {
        if (a[i] <= k)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    for (int j = n - 1; j >= i; j--)
    {
        if (a[j] <= k)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
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
