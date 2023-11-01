// Problem: B. Qingshan Loves Strings
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    char choosen = 't';
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1] && choosen == 't')
        {
            choosen = s[i];
        }
        else if (s[i] == s[i - 1])
        {
            if (s[i] != choosen)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    if (choosen == 't')
    {
        cout << "Yes" << endl;
        return;
    }
    else
    {
        for (int i = 1; i < m; i++)
        {
            if (t[i] == t[i - 1])
            {
                cout << "No" << endl;
                return;
            }
        }
        char to_find = (choosen == '1' ? '0' : '1');
        if (t[0] == to_find && t[m - 1] == to_find)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
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
