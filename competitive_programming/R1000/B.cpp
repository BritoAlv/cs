// Problem: B. Make Equal
// Contest: Codeforces - Codeforces Round 925 (Div. 3)
// URL: https://codeforces.com/contest/1931/problem/B
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

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    ull sum = 0;
    forn
    {
        cin >> a[i];
        sum += a[i];
    }
    int to_deposit = sum / n;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < to_deposit)
        {
            cout << "NO" << endl;
            return;
        }
        else if (a[i] > to_deposit)
        {
            a[i + 1] += a[i] - to_deposit;
        }
    }
    if (a[n - 1] == to_deposit)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
