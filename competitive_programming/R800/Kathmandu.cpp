// Problem: K. Kathmandu
// Contest: Codeforces - 2021-2022 ACM-ICPC Brazil Subregional Programming Contest
// URL: https://codeforces.com/gym/103388/problem/K
// Memory Limit: 1024 MB
// Time Limit: 250 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

void Solve()
{
    int t, d, m;
    cin >> m >> d >> t;
    int a[t + 2];
    a[0] = 0;
    a[t + 1] = d;
    for (int i = 1; i <= t; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < t + 2; i++)
    {
        if (a[i] - a[i - 1] >= m)
        {
            cout << "Y" << endl;
            return;
        }
    }
    cout << "N" << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}
