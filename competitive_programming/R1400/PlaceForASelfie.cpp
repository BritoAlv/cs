// Problem: C. Place for a Selfie
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1805/C
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
using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    set<long long> VG;
    forn
    {
        long long a;
        cin >> a;
        VG.insert(a);
    }
    form
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (VG.lower_bound(b) != VG.begin())
        {
            // largest element less than b.
            auto x = VG.lower_bound(b);
            x--;
            long long found = *x;
            if ((found - b) * (found - b) < 4 * a * c)
            {
                cout << "YES" << endl;
                cout << found << endl;
                continue;
            }
        }
        if (VG.lower_bound(b) != VG.end())
        {
            // smallest element greater or equal than b.
            long long found = *VG.lower_bound(b);
            if ((found - b) * (found - b) < 4 * a * c)
            {
                cout << "YES" << endl;
                cout << found << endl;
                continue;
            }
        }
        cout << "NO" << endl;
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
