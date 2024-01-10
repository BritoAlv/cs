// Problem: D. Row Major
// Contest: Codeforces - Codeforces Round 884 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1844/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int mcd(int a, int b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, a % b);
    }
}

void Solve()
{
    int n;
    cin >> n;
    int mod = 1;
    if (n == 2)
    {
        cout << "ab" << endl;
        return;
    }
    for (int i = 2; i < n; i++)
    {
        if (mcd(n, i) != i)
        {
            mod = i;
            break;
        }
    }
    forn
    {
        cout << char('a' + (i % mod));
    }
    cout << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
