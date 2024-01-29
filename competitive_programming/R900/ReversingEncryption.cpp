// Problem: B. Reversing Encryption
// Contest: Codeforces - Codeforces Round 490 (Div. 3)
// URL: https://codeforces.com/contest/999/problem/B
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
    vector<char> r(n);
    forn
    {
        cin >> r[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            vector<char> neww(i);
            for (int j = 0; j < i; j++)
            {
                neww[j] = r[j];
            }
            for (int j = i - 1; j >= 0; j--)
            {
                r[j] = neww[(i - 1) - j];
            }
        }
    }
    forn
    {
        cout << r[i];
    }
    cout << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
