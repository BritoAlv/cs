// Problem: A. Square
// Contest: Codeforces - Codeforces Round 920 (Div. 3)
// URL: https://codeforces.com/contest/1921/problem/A
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
    vector<pair<int, int>> A;
    for (int i = 0; i < 4; i++)
    {
        int a, b;
        cin >> a >> b;
        A.pb({a, b});
    }
    sort(A.begin(), A.end());
    cout << (A[1].second - A[0].second) * (A[1].second - A[0].second) << endl;
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
