// Problem: B. Binary Path
// Contest: Codeforces - Codeforces Round 930 (Div. 2)
// URL: https://codeforces.com/contest/1937/problem/B
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> eq(n, 0);
    eq[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i - 1])
        {
            eq[i] = eq[i - 1] + 1;
        }
        else
        {
            eq[i] = 0;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] == '1' && b[i] == '0')
        {
            for (int j = 0; j <= i; j++)
            {
                cout << a[j];
            }
            for (int j = i; j < n; j++)
            {
                cout << b[j];
            }
            cout << endl;
            cout << eq[i] + 1 << endl;
            return;
        }
    }
    for (int j = 0; j <= n - 1; j++)
    {
        cout << a[j];
    }
    for (int j = n - 1; j < n; j++)
    {
        cout << b[j];
    }
    cout << endl;
    cout << eq[n - 1] + 1 << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
