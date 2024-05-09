// Problem: B. Fedya and Array
// Contest: Codeforces - Codeforces Round 852 (Div. 2)
// URL: https://codeforces.com/contest/1793/problem/B
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
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
        cout << (a - b + 1) + ((a - 1) - (b + 1) + 1) << endl;
        for (int i = a; i >= b; i--)
        {
            cout << i << wp;
        }
        for (int i = b + 1; i <= a - 1; i++)
        {
            cout << i << wp;
        }
        cout << endl;
    }
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
