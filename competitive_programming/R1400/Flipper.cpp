// Problem: D. Flipper
// Contest: Codeforces - Codeforces Round 874 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1833/D
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
    vector<int> best_sol;
    pair<int, int> lr = {1, n};
    forn
    {
        best_sol.pb(a[n - 1 - i]);
    }
    vector<int> r_s;
    forn
    {
        if (a[i] == n || a[i] == n - 1)
        {
            r_s.pb(i);
            if (i > 0)
            {
                r_s.pb(i - 1);
            }
        }
    }
    for (int l = 0; l < n; l++)
    {
        for (auto r : r_s)
        {
            if (r >= l)
            {
                vector<int> new_ans;
                for (int i = r + 1; i < n; i++)
                {
                    new_ans.pb(a[i]);
                }
                for (int i = r; i >= l; i--)
                {
                    new_ans.pb(a[i]);
                }
                for (int i = 0; i < l; i++)
                {
                    new_ans.pb(a[i]);
                }
                forn
                {
                    if (best_sol[i] > new_ans[i])
                    {
                        break;
                    }
                    else if (best_sol[i] < new_ans[i])
                    {
                        best_sol = new_ans;
                        lr = {l + 1, r + 1};
                        break;
                    }
                }
            }
        }
    }
    for (auto x : best_sol)
    {
        cout << x << wp;
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
