// Problem: C. Serval and Toxel's Arrays
// Contest: Codeforces - Codeforces Round 853 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1789/C
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
    int n, m;
    cin >> n >> m;
    int a[n];
    map<int, vector<int>> count;
    for (int i = 1; i <= n + m; i++)
    {
        count[i] = vector<int>();
    }
    forn
    {
        cin >> a[i];
        count[a[i]].pb(0);
    }
    form
    {
        int pos, newvalue;
        cin >> pos >> newvalue;
        pos--;
        count[a[pos]].pb(j + 1);
        count[newvalue].pb(j + 1);
        a[pos] = newvalue;
    }
    ull ans = n;
    ans *= m + 1;
    ans *= m;
    for (auto &x : count)
    {
        if (x.second.sz % 2 == 1)
        {
            x.second.pb(m + 1);
        }
    }

    for (auto &x : count)
    {
        x.second.pb(0);
        for (int i = 0; i < x.second.sz - 1; i += 2)
        {
            x.second.back() += (x.second[i + 1] - x.second[i]);
        }
        ans -= ((ull)x.second.back() * (x.second.back() - 1)) / 2;
    }
    cout << ans << endl;
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
