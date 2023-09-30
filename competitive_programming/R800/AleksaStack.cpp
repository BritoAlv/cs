// Problem: B. Aleksa and Stack
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/contest/1878/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int start = 1;
    while (n > 0)
    {
        cout << start << wp;
        start += 2;
        n--;
    }
    cout << endl;
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
