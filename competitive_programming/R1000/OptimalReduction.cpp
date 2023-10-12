// Problem: B. Optimal Reduction
// Contest: Codeforces - Codeforces Round 812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/B
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
    int n;
    cin >> n;
    bool is_increasing = true;
    bool works = true;
    int s;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        int t;
        cin >> t;
        if (is_increasing && t < s)
        {
            is_increasing = false;
        }
        else if (!is_increasing && t > s)
        {
            works = false;
        }
        s = t;
    }

    cout << (works ? "YES" : "NO") << endl;

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
