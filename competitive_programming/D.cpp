// Problem: D. Tandem Repeats?
// Contest: Codeforces - Educational Codeforces Round 163 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1948/problem/D
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

int z_function(string s, int start, int end)
{
    int n = end - start + 1;
    int maxx = 0;
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
            if (z[i] == i)
            {
                if (maxx == -1 || z[i] > maxx)
                {
                    maxx = z[i];
                }
            }
        }
        while (i + z[i] < n &&
               (s[start + z[i]] == s[start + i + z[i]] || s[start + z[i]] == '?' || s[start + i + z[i]] == '?'))
        {
            if (s[start + z[i]] == '?' && s[start + i + z[i]] != '?')
            {
                s[start + z[i]] = s[start + i + z[i]];
            }
            else if (s[start + i + z[i]] == '?' && s[start + z[i]] != '?')
            {
                s[start + i + z[i]] = s[start + z[i]];
            }
            z[i]++;
            if (z[i] == i)
            {
                if (maxx == -1 || z[i] > maxx)
                {
                    maxx = z[i];
                }
            }
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return maxx;
}

void Solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n, 0);
    forn
    {
        ans[i] = z_function(s, i, n - 1);
    }
    int maxx = ans[0];
    forn
    {
        maxx = max(maxx, ans[i]);
    }
    cout << 2 * maxx << endl;

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
