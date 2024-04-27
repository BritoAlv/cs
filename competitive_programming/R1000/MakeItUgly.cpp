// Problem: B. Make It Ugly
// Contest: Codeforces - Educational Codeforces Round 164 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1954/problem/B
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
    int n;
    cin >> n;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> dif_pos;
    dif_pos.pb(-1);
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            dif_pos.pb(i);
        }
    }
    dif_pos.pb(n);
    vector<int> difs;
    for (int i = 1; i < dif_pos.sz; i++)
    {
        difs.pb(dif_pos[i] - dif_pos[i - 1]);
    }
    sort(difs.begin(), difs.end());
    if (difs[0] == n + 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << difs[0] - 1 << endl;
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