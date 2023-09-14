// Problem: A. Split it!
// Contest: Codeforces - Codeforces Round 706 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1496/A
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

int test_cases;

void Solve()
{
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    if (n < 2 * k + 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        bool matched = true;
        for (int i = 0; i < k; i++)
        {
            if (S[i] != S[n - 1 - i])
            {
                matched = false;
                break;
            }
        }
        if (matched)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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
