// Problem: C1. Magnitude (Easy Version)
// Contest: Codeforces - Codeforces Global Round 26
// URL: https://codeforces.com/contest/1984/problem/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int n;
    cin >> n;
    long long a[n];
    long long maxx = 0;
    forn
    {
        cin >> a[i];
    }
    vector<long long> psums(n);
    psums[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        psums[i] = a[i] + psums[i - 1];
    }
    long long best = -1;
    long long c = 0;
    forn
    {
        best = max(best, abs(c + a[i]) + psums[n - 1] - psums[i]);
        c += a[i];
    }
    cout << best << endl;
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
