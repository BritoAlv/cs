// Problem: E1. Unforgivable Curse (easy version)
// Contest: Codeforces - Codeforces Round 855 (Div. 3)
// URL: https://codeforces.com/contest/1800/problem/E1
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
    int n, k;
    cin >> n >> k;
    int countS[26];
    int countE[26];
    for (int i = 0; i < 26; i++)
    {
        countS[i] = countE[i] = 0;
    }
    vector<char> S(n);
    vector<char> E(n);
    forn
    {
        cin >> S[i];
        countS[S[i] - 'a']++;
    }
    forn
    {
        cin >> E[i];
        countE[E[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (countS[i] != countE[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    vector<int> to_check;
    if (n <= 2 * k)
    {
        forn
        {
            if (i - k < 0 && i + k > n - 1)
            {
                to_check.pb(i);
            }
        }
    }
    for (auto x : to_check)
    {
        if (S[x] != E[x])
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
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
