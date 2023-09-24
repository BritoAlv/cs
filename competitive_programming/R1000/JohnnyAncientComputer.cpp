// Problem: A. Johnny and Ancient Computer
// Contest: Codeforces - Codeforces Round 647 (Div. 2) - Thanks, Algo Muse!
// URL: https://codeforces.com/problemset/problem/1362/A
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
    long long a, b;
    cin >> a >> b;
    int a_2_count = 0;
    int b_2_count = 0;
    while (a % 2 == 0)
    {
        a = a / 2;
        a_2_count++;
    }
    while (b % 2 == 0)
    {
        b = b / 2;
        b_2_count++;
    }

    if (a != b)
    {
        cout << -1 << endl;
    }
    else
    {
        int dif = abs(a_2_count - b_2_count);
        cout << (dif / 3) + (dif % 3 > 0 ? 1 : 0) << endl;
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
