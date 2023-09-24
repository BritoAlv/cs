// Problem: C. Target Practice
// Contest: Codeforces - Codeforces Round 898 (Div. 4)
// URL: https://codeforces.com/contest/1873/problem/C
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
    int answer = 0;
    for (int x = 1; x <= 10; x++)
    {
        for (int y = 1; y <= 10; y++)
        {
            char t;
            cin >> t;
            if (t == 'X')
            {
                int m = (x > 5 ? 11 - x : x);
                int n = (y > 5 ? 11 - y : y);
                answer += min(m, n);
            }
        }
    }
    cout << answer << endl;
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
