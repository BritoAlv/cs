// Problem: B. Chemistry
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1883/B
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

void Solve()
{
    int n, k;
    cin >> n >> k;
    int a[26];
    for (int i = 0; i < 26; i++)
    {
        a[i] = 0;
    }
    forn
    {
        char t;
        cin >> t;
        a[t - 'a']++;
    }
    int to_choose = n - k - (n - k) % 2;
    for (int i = 0; i < 26; i++)
    {
        int at_most = (a[i] / 2) * 2;
        a[i] -= min(at_most, to_choose);
        to_choose -= min(at_most, to_choose);
        if (to_choose == 0)
        {
            break;
        }
    }
    if (to_choose > 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        if ((n - k) % 2 == 1)
        {
            for (int i = 0; i < 26; i++)
            {
                if (a[i] > 0)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
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
