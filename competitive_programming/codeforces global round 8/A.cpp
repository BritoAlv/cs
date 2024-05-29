// Problem: A. C+=
// Contest: Codeforces - Codeforces Global Round 8
// URL: https://codeforces.com/contest/1368/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
    int a, b, n;
    cin >> a >> b >> n;
    int s1 = min(a, b);
    int s2 = max(a, b);
    int ops = 0;
    while (s2 <= n)
    {
        int s3 = s2 + s1;
        s1 = s2;
        s2 = s3;
        ops++;
    }
    cout << ops << endl;
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
