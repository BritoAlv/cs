// Problem: B. Progressive Square
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/contest/1955/problem/B
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
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<vector<ull>> mm;
    forn
    {
        mm.pb(vector<ull>(n));
    }
    vector<ull> inp(n * n);
    for (int i = 0; i < n * n; i++)
    {
        cin >> inp[i];
    }
    sort(inp.begin(), inp.end());
    mm[0][0] = inp[0];
    for (int i = 1; i < n; i++)
    {
        mm[i][0] = mm[i - 1][0] + c;
    }
    forn
    {
        for (int j = 1; j < n; j++)
        {
            mm[i][j] = mm[i][j - 1] + d;
        }
    }
    vector<ull> inp2;
    int m = n;
    forn
    {
        form
        {
            inp2.pb(mm[i][j]);
        }
    }
    sort(inp2.begin(), inp2.end());
    for (int i = 0; i < n * n; i++)
    {
        if (inp2[i] != inp[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
