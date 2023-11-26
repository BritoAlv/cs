// Problem: C. Phase Shift
// Contest: Codeforces - Codeforces Round 824 (Div. 2)
// URL: https://codeforces.com/contest/1735/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    int n;
    cin >> n;
    vector<char> t(n);
    forn
    {
        cin >> t[i];
    }
    char c[26];
    for (int i = 0; i < 26; i++)
    {
        c[i] = '0';
    }
    vector<char> S(n);
    forn
    {
        int j = 0;
        for (; j < 26; j++)
        {
            if (c[j] == t[i])
            {
                S[i] = 'a' + j;
                break;
            }
        }
        if (j == 26)
        {
            // first time seen this letter.
            char last = t[i];
            while (c[last - 'a'] != '0')
            {
                last = c[last - 'a'];
            }
            int z = 0;
            for (; z < 26; z++)
            {
                if (c[z] == '0' && ('a' + z) != last)
                {
                    S[i] = 'a' + z;
                    c[z] = t[i];
                    break;
                }
            }
            if (z == 26)
            {
                S[i] = last;
            }
        }
    }
    forn
    {
        cout << S[i];
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
