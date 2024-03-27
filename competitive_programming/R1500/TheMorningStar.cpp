// Problem: G. The Morning Star
// Contest: Codeforces - Codeforces Round 886 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1850/G
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
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

void BruteSolve()
{
    return;
}

void Solve()
{
    int n;
    cin >> n;
    vector<pi> p(n);
    forn
    {
        cin >> p[i].first >> p[i].second;
    }
    map<int, vector<int>> X;
    map<int, vector<int>> Y;
    map<int, vector<int>> Z1;
    map<int, vector<int>> Z2;
    ull ans = 0;
    forn
    {
        if (X.find(p[i].first) == X.end())
        {
            X[p[i].first] = vector<int>();
        }
        X[p[i].first].pb(i);
    }
    for (auto t : X)
    {
        ull aport = t.second.size();
        aport *= (aport - 1);
        ans += aport;
    }

    forn
    {
        if (Y.find(p[i].second) == Y.end())
        {
            Y[p[i].second] = vector<int>();
        }
        Y[p[i].second].pb(i);
    }
    for (auto t : Y)
    {
        ull aport = t.second.size();
        aport *= (aport - 1);
        ans += aport;
    }
    forn
    {
        if (Z1.find(p[i].second - p[i].first) == Z1.end())
        {
            Z1[p[i].second - p[i].first] = vector<int>();
        }
        Z1[p[i].second - p[i].first].pb(i);
    }
    for (auto t : Z1)
    {
        ull aport = t.second.size();
        aport *= (aport - 1);
        ans += aport;
    }

    forn
    {
        if (Z2.find(p[i].second + p[i].first) == Z2.end())
        {
            Z2[p[i].second + p[i].first] = vector<int>();
        }
        Z2[p[i].second + p[i].first].pb(i);
    }
    for (auto t : Z2)
    {
        ull aport = t.second.size();
        aport *= (aport - 1);
        ans += aport;
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
