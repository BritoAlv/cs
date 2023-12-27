// Problem: H. Beppa and SwerChat
// Contest: Codeforces - SWERC 2022-2023 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1776/H
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
    int n;
    cin >> n;
    int a[n];
    int b[n];
    map<int, int> C;
    forn
    {
        cin >> a[i];
        C[a[i]] = i;
    }
    forn
    {
        cin >> b[i];
    }
    vector<int> found;
    for (int i = n - 1; i >= 0; i--)
    {
        int a = C[b[i]];
        if (found.size() == 0 || found.back() > a)
        {
            found.pb(a);
        }
        else
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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
