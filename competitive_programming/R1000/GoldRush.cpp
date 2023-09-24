// Problem: D. Gold Rush
// Contest: Codeforces - Codeforces Round 871 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1829/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: notice that because each time the number gets divided by 3,
// so simulate the problem is allowed.
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
    int n, m;
    cin >> n >> m;
    queue<int> to_process;
    to_process.push(n);
    while (to_process.size() > 0)
    {
        int a = to_process.front();
        to_process.pop();
        if (a == m)
        {
            cout << "YES" << endl;
            return;
        }
        else if (a % 3 != 0 || a < m)
        {
        }
        else
        {
            to_process.push(a / 3);
            to_process.push(2 * (a / 3));
        }
    }

    cout << "NO" << endl;

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
