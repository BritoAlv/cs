// Problem: E. Add Modulo 10
// Contest: Codeforces - Codeforces Round 811 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1714/E
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

int equivalent(int a, int b)
{
    if ((a % 5) == 0 || (b % 5) == 0)
    {
        int maxx = max(b, a);
        int minn = min(b, a);
        return maxx == minn || (minn + 5 == maxx && minn % 10 != 0);
    }
    while ((a % 10) != 2)
    {
        a += a % 10;
    }
    while ((b % 10) != 2)
    {
        b += b % 10;
    }
    int d = max(b, a) - min(b, a);
    return (d % 20) == 0;
}

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    sort(a, a + n);
    forn
    {
        if (!equivalent(a[i], a[n - 1]))
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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
