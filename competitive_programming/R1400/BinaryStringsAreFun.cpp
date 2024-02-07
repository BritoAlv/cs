// Problem: C. Binary Strings are Fun
// Contest: Codeforces - Codeforces Round 838 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1762/C
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

ull fast_exp(ull base, ull exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp % 2 == 0)
    {
        ull ans1 = fast_exp(base, exp / 2);
        ans1 *= ans1;
        ans1 %= 998244353;
        return ans1;
    }
    else
    {
        ull ans1 = fast_exp(base, (exp - 1) / 2);
        ans1 *= ans1;
        ans1 %= 998244353;
        ans1 *= base;
        ans1 %= 998244353;
        return ans1;
    }
}

void Solve()
{
    int n;
    cin >> n;
    ull ans = 0;
    char a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> exp(n);
    exp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            exp[i] = 0;
        }
        else
        {
            exp[i] = exp[i - 1] + 1;
        }
    }
    forn
    {
        ans += fast_exp(2, exp[i]);
        ans %= 998244353;
    }
    cout << ans << endl;
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