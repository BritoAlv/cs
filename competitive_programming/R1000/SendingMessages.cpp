// Problem: C. Sending Messages
// Contest: Codeforces - Codeforces Round 920 (Div. 3)
// URL: https://codeforces.com/contest/1921/problem/C
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

void Solve()
{
    long long f, a, b;
    int n;
    cin >> n >> f >> a >> b;
    int A[n + 1];
    A[0] = 0;
    forn
    {
        cin >> A[i + 1];
    }
    long long used = 0;
    for (int i = 1; i <= n; i++)
    {
        used += min(b, a * (A[i] - A[i - 1]));
    }
    cout << (used < f ? "YES" : "NO") << endl;
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
