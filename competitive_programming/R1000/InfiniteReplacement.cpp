// Problem: C. Infinite Replacement
// Contest: Codeforces - Codeforces Round 786 (Div. 3)
// URL: https://codeforces.com/contest/1674/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    string s, t;
    cin >> s >> t;
    if (t.size() == 1 && t[0] == 'a')
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        bool a = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == 'a')
            {
                a = 1;
                break;
            }
        }
        if (a)
        {
            cout << -1 << endl;
        }
        else
        {
            long long ans = 1;
            for (int i = 1; i <= s.size(); i++)
            {
                ans *= 2;
            }
            cout << ans << endl;
        }
    }
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
