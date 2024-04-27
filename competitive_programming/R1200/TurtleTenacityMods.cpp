// Problem: D. Turtle Tenacity: Continual Mods
// Contest: Codeforces - Codeforces Round 929 (Div. 3)
// URL: https://codeforces.com/contest/1933/problem/D
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

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
    if (a[0] == 1)
    {
        if (a[1] == 1)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            cout << "YES" << endl;
            return;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] % a[0] != 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[0])
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
