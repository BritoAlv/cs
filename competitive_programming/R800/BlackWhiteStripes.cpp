// Problem: D. Black and White Stripe
// Contest: Codeforces - Codeforces Round 797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    vector<char> st(n);
    forn
    {
        cin >> st[i];
    }
    vector<int> ans(n - k + 1, 0);
    for (int i = 0; i < k; i++)
    {
        ans[0] += st[i] == 'W';
    }
    for (int i = 1; i < n - k + 1; i++)
    {
        ans[i] = ans[i - 1] - (st[i - 1] == 'W') + (st[i + k - 1] == 'W');
    }
    int minn = ans[0];
    for (int i = 0; i < n - k + 1; i++)
    {
        minn = min(minn, ans[i]);
    }
    cout << minn << endl;
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
