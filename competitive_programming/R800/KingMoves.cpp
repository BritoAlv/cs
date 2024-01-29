// Problem: A. King Moves
// Contest: Codeforces - Educational Codeforces Round 16
// URL: https://codeforces.com/contest/710/problem/A
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
    char t;
    cin >> t;
    int r = (t - 'a');
    int l;
    cin >> l;
    l--;
    if (r % 7 == 0 && l % 7 == 0)
    {
        cout << 3 << endl;
    }
    else if (r % 7 == 0 || l % 7 == 0)
    {
        cout << 5 << endl;
    }
    else
    {
        cout << 8 << endl;
    }
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
