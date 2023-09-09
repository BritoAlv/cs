// Problem: B. Power Walking
// Contest: Codeforces - Codeforces Round 773 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1642/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof: just implementation
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
    int n;
    cin >> n;
    set<int> sett;
    forn
    {
        int t;
        cin >> t;
        sett.insert(t);
    }
    forn
    {
        cout << sett.size() + max(0, (i + 1) - sett.size()) << ' ';
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
