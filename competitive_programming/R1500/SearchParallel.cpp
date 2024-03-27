// Problem: C. Search in Parallel
// Contest: Codeforces - Educational Codeforces Round 146 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1814/C
// Memory Limit: 512 MB
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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int, int>> p(n);
    forn
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    vector<int> g1;
    vector<int> g2;
    for (int i = n - 1; i >= 0; i--)
    {
        ull option1 = (ull)(g1.size() + 1) * (ull)p[i].first * s1;
        ull option2 = (ull)(g2.size() + 1) * (ull)p[i].first * s2;
        if (option1 < option2)
        {
            g1.pb(p[i].second + 1);
        }
        else if (option1 > option2)
        {
            g2.pb(p[i].second + 1);
        }
        else
        {
            if (s1 > s2)
            {
                g2.pb(p[i].second + 1);
            }
            else
            {
                g1.pb(p[i].second + 1);
            }
        }
    }
    cout << g1.size() << wp;
    for (auto x : g1)
    {
        cout << x << wp;
    }
    cout << endl;
    cout << g2.size() << wp;
    for (auto x : g2)
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
