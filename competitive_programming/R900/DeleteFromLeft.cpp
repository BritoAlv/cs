// Problem: B. Delete from the Left
// Contest: Codeforces - Codeforces Round 496 (Div. 3)
// URL: https://codeforces.com/contest/1005/problem/B
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
    string s, t;
    cin >> s >> t;
    int pointer1 = s.size() - 1;
    int pointer2 = t.size() - 1;
    while (pointer1 >= 0 && pointer2 >= 0 && s[pointer1] == t[pointer2])
    {
        pointer1--;
        pointer2--;
    }
    cout << pointer1 + pointer2 + 2 << endl;
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