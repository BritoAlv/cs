// Problem: C. Insert Zero and Invert Prefix
// Contest: Codeforces - Codeforces Round 876 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1839/C
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
    stack<vector<int>> s;
    forn
    {
        vector<int> d;
        if (a[i] == 1)
        {
            d.pb(1);
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == 1)
                {
                    d.pb(1);
                }
                else
                {
                    d.pb(0);
                    i = j;
                    break;
                }
            }
        }
        else
        {
            d.pb(0);
        }
        if (d[d.size() - 1] == 1)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            s.push(d);
        }
    }
    cout << "YES" << endl;
    while (s.size() > 0)
    {
        auto top = s.top();
        s.pop();
        for (int i = 0; i < top.size() - 1; i++)
        {
            cout << 0 << wp;
        }
        cout << top.size() - 1 << wp;
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
