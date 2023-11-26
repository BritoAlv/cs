// Problem: F. Alex's whims
// Contest: Codeforces - Codeforces Round 909 (Div. 3)
// URL: https://codeforces.com/contest/1899/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n, q;
    cin >> n >> q;
    int qu[q];
    for (int i = 0; i < q; i++)
    {
        cin >> qu[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << i + 1 << wp << i + 2 << endl;
    }
    int last_con = n - 1;
    int con_dist = n - 1;
    for (int i = 0; i < q; i++)
    {
        if (qu[i] == con_dist)
        {
            cout << -1 << wp << -1 << wp << -1 << endl;
        }
        else
        {
            cout << n << wp << last_con << wp << qu[i] << endl;
            con_dist = qu[i];
            last_con = qu[i];
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
