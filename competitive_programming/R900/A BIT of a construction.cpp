// Problem: B. A BIT of a Construction
// Contest: Codeforces - Codeforces Round 940 (Div. 2) and CodeCraft-23
// URL: https://codeforces.com/contest/1957/problem/B
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    int exp = 0;
    int k2 = k;
    while (k2 > 0)
    {
        k2 /= 2;
        exp++;
    }
    int nn = 1;
    for (int i = 1; i < exp; i++)
    {
        nn *= 2;
    }
    if (n == 1)
    {
        cout << k << endl;
        return;
    }
    cout << nn - 1 << wp << (k - nn + 1) << wp;
    for (int i = 2; i < n; i++)
    {
        cout << 0 << wp;
    }
    cout << endl;
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
