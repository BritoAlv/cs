// Problem: B. Symmetric Encoding
// Contest: Codeforces - Codeforces Round 946 (Div. 3)
// URL: https://codeforces.com/contest/1974/problem/B
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
    vector<char> s(n);
    forn
    {
        cin >> s[i];
    }
    set<char> result;
    forn
    {
        result.insert(s[i]);
    }
    vector<char> ordered;
    for (auto x : result)
    {
        ordered.pb(x);
    }
    vector<char> ans(n);
    forn
    {
        char t = s[i];
        for (int j = 0; j < ordered.sz; j++)
        {
            if (ordered[j] == t)
            {
                ans[i] = ordered[ordered.sz - 1 - j];
            }
        }
    }
    forn
    {
        cout << ans[i];
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
