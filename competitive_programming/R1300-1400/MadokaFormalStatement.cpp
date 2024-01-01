// Problem: C. Madoka and Formal Statement
// Contest: Codeforces - Codeforces Round 818 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1717/C
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
    forn
    {
        cin >> b[i];
    }
    forn
    {
        if (a[i] > b[i])
        {
            cout << "NO" << endl;
            return;
        }
        else if (b[i] >= b[(i + 1) % n] + 2 && a[i] != b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
