// Problem: D. Very Different Array
// Contest: Codeforces - Codeforces Round 920 (Div. 3)
// URL: https://codeforces.com/contest/1921/problem/D
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> A;
    forn
    {
        int a;
        cin >> a;
        A.pb({a, i});
    }
    sort(A.begin(), A.end());
    int b[m];
    form
    {
        cin >> b[j];
    }
    sort(b, b + m);
    long long sum1 = 0;
    int ss = 0;
    while (ss < n && abs(A[ss].first - b[m - 1 - ss]) >= abs(A[ss].first - b[n - 1 - ss]))
    {
        sum1 += abs(A[ss].first - b[m - 1 - ss]);
        ss++;
    }
    for (int i = ss; i < n; i++)
    {
        sum1 += abs(A[i].first - b[n - 1 - i]);
    }
    cout << sum1 << endl;
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
