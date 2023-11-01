// Problem: A. Ambitious Kid
// Contest: Codeforces - COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1866/problem/A
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
    int answer = 1e6;
    forn
    {
        int a;
        cin >> a;
        if (max(a, -a) < answer)
        {
            answer = max(a, -a);
        }
    }
    cout << answer << endl;
    return;
}

int main()
{
    Solve();
    return 0;
}
