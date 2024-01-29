// Problem: D. Super-Permutation
// Contest: Codeforces - Codeforces Round 867 (Div. 3)
// URL: https://codeforces.com/contest/1822/problem/D
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

void Solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        vector<int> ans(n);
        ans[0] = n;
        ans[1] = n - 1;
        for (int i = 2; i < n; i += 2)
        {
            ans[i] = i;
        }
        for (int i = n - 1; i >= 2; i -= 2)
        {
            ans[i] = n - i;
        }
        forn
        {
            cout << ans[i] << wp;
        }
        cout << endl;
    }
    else
    {
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
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
