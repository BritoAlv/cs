// Problem: A. Two Vessels
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

int max(int a, int b)
{
    return a > b ? a : b;
}

void Solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int to_quit = max(a, b) - (a + b) / 2;
    int one_more = (to_quit % c == 0 ? 0 : 1);
    cout << to_quit / c + one_more << endl;
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
