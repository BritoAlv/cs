// Problem: C. Grouping Increases
// Contest: Codeforces - Hello 2024
// URL: https://codeforces.com/contest/1919/problem/C
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
    forn
    {
        cin >> a[i];
    }
    vector<int> g1;
    vector<int> g2;
    g1.pb(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (g1.size() > 0 && g2.size() > 0)
        {
            if (a[i] > g1.back() && a[i] > g2.back())
            {
                if (g1.back() < g2.back())
                {
                    g1.pb(a[i]);
                }
                else
                {
                    g2.pb(a[i]);
                }
            }
            else if (a[i] > g1.back())
            {
                g2.pb(a[i]);
            }
            else if (a[i] > g2.back())
            {
                g1.pb(a[i]);
            }
            else
            {
                if (g1.back() < g2.back())
                {
                    g1.pb(a[i]);
                }
                else
                {
                    g2.pb(a[i]);
                }
            }
        }
        else
        {
            if (a[i] <= g1.back())
            {
                g1.pb(a[i]);
            }
            else
            {
                g2.pb(a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < g1.size(); i++)
    {
        if (g1[i] > g1[i - 1])
        {
            ans++;
        }
    }
    for (int i = 1; i < g2.size(); i++)
    {
        if (g2[i] > g2[i - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
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