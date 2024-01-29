// Problem: C. Min-Max Array Transformation
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1721/C
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
    int b[n];
    forn
    {
        cin >> a[i];
    }
    set<int> A;
    forn
    {
        cin >> b[i];
        A.insert(b[i]);
    }
    forn
    {
        cout << (*A.lower_bound(a[i]) - a[i]) << wp;
    }
    cout << endl;
    int r[n];
    r[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = 0;
        if (a[i + 1] <= b[i])
        {
            r[i] = r[i + 1] + 1;
        }
    }
    forn
    {
        cout << b[i + r[i]] - a[i] << wp;
    }
    cout << endl;
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
