// Problem: B. Equal XOR
// Contest: Codeforces - Codeforces Round 934 (Div. 2)
// URL: https://codeforces.com/contest/1944/problem/B
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

void Solve()
{
    int n, k;
    cin >> n >> k;
    set<int> a;
    set<int> b;
    forn
    {
        int t;
        cin >> t;
        a.insert(t);
    }
    forn
    {
        int t;
        cin >> t;
        b.insert(t);
    }
    vector<int> aa;
    vector<int> bb;
    for (int i = 1; i <= n; i++)
    {
        if (aa.sz < 2 * k && a.find(i) != a.end() && b.find(i) == b.end())
        {
            aa.pb(i);
            aa.pb(i);
        }
        if (bb.sz < 2 * k && b.find(i) != b.end() && a.find(i) == a.end())
        {
            bb.pb(i);
            bb.pb(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a.find(i) != a.end() && b.find(i) != b.end() && aa.sz < 2 * k)
        {
            aa.pb(i);
            bb.pb(i);
        }
    }

    for (auto x : aa)
    {
        cout << x << wp;
    }
    cout << endl;
    for (auto x : bb)
    {
        cout << x << wp;
    }
    cout << endl;
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
