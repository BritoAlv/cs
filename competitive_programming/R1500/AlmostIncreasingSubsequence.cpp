// Problem: A. Almost Increasing Subsequence
// Contest: Codeforces - Codeforces Round 869 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1817/A
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> ans(n, 0);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (i >= 2 && a[i - 2] >= a[i - 1] && a[i - 1] >= a[i])
        {
            ans[i] = ans[i - 1];
        }
        else
        {
            ans[i] = ans[i - 1] + 1;
        }
    }
    while (q > 0)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (r - l <= 1)
        {
            cout << r - l + 1 << endl;
        }
        else if (l == 0)
        {
            cout << ans[r] << endl;
        }
        else if (l == n - 1)
        {
            cout << 1 << endl;
        }
        else
        {
            if (a[l - 1] >= a[l] && a[l] >= a[l + 1])
            {
                cout << ans[r] - ans[l] + 2 << endl;
            }
            else
            {
                cout << ans[r] - ans[l] + 1 << endl;
            }
        }
        q--;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}