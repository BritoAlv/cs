// Problem: C. Clock and Strings
// Contest: Codeforces - Codeforces Round 944 (Div. 4)
// URL: https://codeforces.com/contest/1971/problem/C
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int last = -1;
    for (int i = 1; i <= 12; i++)
    {
        if (i == a || i == b)
        {
            if (last == 0)
            {
                cout << "NO" << endl;
                return;
            }
            last = 0;
        }
        else if (i == c || i == d)
        {
            if (last == 1)
            {
                cout << "NO" << endl;
                return;
            }
            last = 1;
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
