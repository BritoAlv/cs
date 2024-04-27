// Problem: C. Nene's Magical Matrix
// Contest: Codeforces - Codeforces Round 939 (Div. 2)
// URL: https://codeforces.com/contest/1956/problem/C
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

void print_op(int type_op, int index, int n)
{
    cout << type_op << wp << index + 1 << wp;
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << wp;
    }
    cout << endl;
}

void Solve()
{
    int n;
    cin >> n;
    ull sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i * (2 * i - 1);
    }
    cout << sum << wp << 2 * n << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        print_op(2, i, n);
        print_op(1, i, n);
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