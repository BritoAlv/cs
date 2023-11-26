// Problem: A. Blackboard List
// Contest: Codeforces - Codeforces Round 877 (Div. 2)
// URL: https://codeforces.com/contest/1838/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    forn
    {
        if (a[i] < 0)
        {
            cout << a[i] << endl;
            return;
        }
    }
    int maxx = -1;
    forn
    {
        maxx = max(a[i], maxx);
    }
    cout << maxx << endl;
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
