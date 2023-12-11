// Problem: C. Removal of Unattractive Pairs
// Contest: Codeforces - Codeforces Round 913 (Div. 3)
// URL: https://codeforces.com/contest/1907/problem/C
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

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }
    forn
    {
        char t;
        cin >> t;
        count[t - 'a']++;
    }
    int most_repeated = -1;
    for (int i = 0; i < 26; i++)
    {
        most_repeated = max(most_repeated, count[i]);
    }
    int countt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == most_repeated)
        {
            countt++;
        }
    }
    // there are n chars.
    // x, n-x.
    // I can delete n - 2*min(x, (n-x))
    if (most_repeated > n - most_repeated)
    {
        cout << n - 2 * min(most_repeated, n - most_repeated) << endl;
    }
    else
    {
        cout << n % 2 << endl;
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