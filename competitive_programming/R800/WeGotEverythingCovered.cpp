// Problem: A. We Got Everything Covered!
// Contest: Codeforces - Codeforces Round 921 (Div. 2)
// URL: https://codeforces.com/contest/1925/problem/A
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
    int n, m;
    cin >> n >> m;
    string s = "";
    forn
    {
        for (int i = 0; i < m; i++)
        {
            s += ('a' + i);
        }
    }
    cout << s << endl;
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
