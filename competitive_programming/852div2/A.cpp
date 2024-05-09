// Problem: A. Yet Another Promotion
// Contest: Codeforces - Codeforces Round 852 (Div. 2)
// URL: https://codeforces.com/contest/1793/problem/A
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a <= b)
    {
        cout << (n / (m + 1)) * m * a + (n % (m + 1)) * a << endl;
    }
    else
    {
        cout << min(n * b, (n / (m + 1)) * m * a + (n % (m + 1)) * b) << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
