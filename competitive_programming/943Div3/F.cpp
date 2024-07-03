// Problem: F. Equal XOR Segments
// Contest: Codeforces - Codeforces Round 943 (Div. 3)
// URL: https://codeforces.com/contest/1968/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
#define ll long long
#define pl pair<ll, ll>
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define exist(container, obj) (container.find(obj) != container.end())
#define yesno(obj) cout << (obj ? "YES" : "NO") << endl
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void Solve()
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi b(n);
    map<int, set<int>> psums;
    psums[0] = set<int>();
    forn
    {
        cin >> a[i];
        b[i] = a[i];
        if (i > 0)
            a[i] ^= a[i - 1];
        if (!exist(psums, a[i]))
        {
            psums[a[i]] = set<int>();
        }
        psums[a[i]].insert(i);
    }
    map<int, set<int>> psums2;
    psums2[0] = set<int>();
    for (int i = n - 2; i >= 0; i--)
    {
        b[i] ^= b[i + 1];
    }
    forn
    {
        if (!exist(psums2, b[i]))
        {
            psums2[b[i]] = set<int>();
        }
        psums2[b[i]].insert(i);
    }
    while (q > 0)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r)
        {
            yesno(0);
            q--;
            continue;
        }
        int sg = -1;
        int lg = -1;
        auto pt = psums[(l > 0 ? a[l - 1] : 0)].lower_bound(r + 1);
        if (pt != psums[(l > 0 ? a[l - 1] : 0)].begin())
        {
            pt--;
            if (*pt >= l)
                sg = *pt;
        }
        auto pt2 = psums2[(r < n - 1 ? b[r + 1] : 0)].upper_bound(l - 1);
        if (pt2 != psums2[(r < n - 1 ? b[r + 1] : 0)].end() && *pt2 <= r)
        {
            lg = *pt2;
        }
        yesno(sg != -1 && lg != -1 && sg >= lg);
        q--;
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
    int start = 0;
    while (test_cases-- > 0)
    {
        cout << start++ << endl;
        Solve();
    }
    return 0;
}
