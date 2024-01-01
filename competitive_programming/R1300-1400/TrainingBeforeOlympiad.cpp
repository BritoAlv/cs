// Problem: C. Training Before the Olympiad
// Contest: Codeforces - Good Bye 2023
// URL: https://codeforces.com/contest/1916/problem/C#
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

int get_loss(int n_odd)
{
    int ans = n_odd / 3;
    if (n_odd % 3 == 1)
    {
        ans += 1;
    }
    return ans;
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
    long long p[n];
    p[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }
    int n_odd = (a[0] % 2);
    cout << a[0] << wp;
    for (int i = 1; i < n; i++)
    {
        n_odd += (a[i] % 2);
        cout << p[i] - get_loss(n_odd) << wp;
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
