// Problem: B. Plus-Minus Split
// Contest: Codeforces - Hello 2024
// URL: https://codeforces.com/contest/1919/problem/B
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
    int n;
    cin >> n;
    vector<char> S(n);
    long long ans = 0;
    forn
    {
        cin >> S[i];
        ans += (S[i] == '+' ? 1 : -1);
    }
    cout << abs(ans) << endl;
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
