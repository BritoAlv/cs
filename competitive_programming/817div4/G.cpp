// Problem: G. Even-Odd XOR
// Contest: Codeforces - Codeforces Round 817 (Div. 4)
// URL: https://codeforces.com/contest/1722/problem/G
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

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = i;
    }
    long long even_xor = 0;
    long long odd_xor = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            even_xor ^= a[i];
        }
        else
        {
            odd_xor ^= a[i];
        }
    }
    long long number = 0;
    for (int i = 0; i <= 30; i++)
    {
        int ev = (even_xor & (1LL << i)) > 0;
        int od = (odd_xor & (1LL << i)) > 0;
        number += (1LL << i) * (ev ^ od);
    }
    a[n - 1] = number;
    if (a[n - 1] <= n - 2)
    {
        forn
        {
            if (a[i] != a[n - 1])
            {
                a[i] += (1LL << 30);
                break;
            }
        }
        a[n - 1] += (1LL << 30);
    }
    forn
    {
        cout << a[i] << wp;
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