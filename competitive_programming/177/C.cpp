// Problem: C. Disappearing Permutation
// Contest: Codeforces - Educational Codeforces Round 177 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2086/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define fori(a, b) for (int i = a; i <= b; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vl a(n);
    vi q(n);
    fori(0, n - 1)
    {
        cin >> a[i];
        a[i]--;
    }
    fori(0, n - 1)
    {
        cin >> q[i];
        q[i]--;
    }
    vi marked2(n, 0);
    vector<set<int>> g;
    fori(0, n - 1)
    {
        if (!marked2[i])
        {
            int st = i;
            g.pb(set<int>());
            g.back().insert(st);
            marked2[st] = g.size();
            while (g.back().count(a[st]) == 0)
            {
                st = a[st];
                g.back().insert(st);
                marked2[st] = g.size();
            }
        }
    }
    vi marked(g.size(), 0);
    int ans = 0;
    fori(0, n - 1)
    {
        int p = marked2[q[i]];
        if (!marked[p - 1])
        {
            ans += g[p - 1].size();
            marked[p - 1] = 1;
        }
        else
        {
        }
        cout << ans << wp;
    }
    cout << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}
