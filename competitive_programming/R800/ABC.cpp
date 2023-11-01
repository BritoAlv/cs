// Problem: A. ABC
// Contest: Codeforces - Codeforces Round 769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/A
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
    string S;
    cin >> S;
    if (S.size() == 1 || S == "01" || S == "10")
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
