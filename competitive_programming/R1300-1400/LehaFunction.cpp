// Problem: C. Leha and Function
// Contest: Codeforces - Codeforces Round 429 (Div. 2)
// URL: https://codeforces.com/contest/841/problem/C
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

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> A;
    forn
    {
        int v;
        cin >> v;
        A.pb({v, i});
    }
    sort(A.begin(), A.end());
    vector<pair<int, int>> B;
    forn
    {
        int v;
        cin >> v;
        B.pb({v, i});
    }
    sort(B.begin(), B.end());
    int ans[n];
    forn
    {
        ans[B[i].second] = A[n - 1 - i].first;
    }
    forn
    {
        cout << ans[i] << wp;
    }
    cout << endl;
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
