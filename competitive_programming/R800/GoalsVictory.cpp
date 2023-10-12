// Problem: A. Goals of Victory
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/A
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
    long long sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t;
        cin >> t;
        sum += t;
    }
    cout << -sum << endl;
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
