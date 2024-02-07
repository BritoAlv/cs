// Problem: D1. Zero-One (Easy Version)
// Contest: Codeforces - Codeforces Round 821 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1733/D1
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
    ull x, y;
    cin >> n >> x >> y;
    vector<char> a(n);
    vector<char> b(n);
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
    }
    vector<int> bp;
    forn
    {
        if (a[i] != b[i])
        {
            bp.pb(i);
        }
    }
    if (bp.size() % 2 == 1)
    {
        cout << -1 << endl;
    }
    else if (bp.size() % 2 == 0)
    {
        if (bp.size() > 2 || bp.size() == 0)
        {
            cout << y * (bp.size() / 2) << endl;
        }
        else
        {
            if (bp[0] + 1 == bp[1])
            {
                cout << min(x, 2 * y) << endl;
            }
            else
            {
                cout << y << endl;
            }
        }
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
