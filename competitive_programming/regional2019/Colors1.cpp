#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<long long, long long>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

long long d(pi A, pi B)
{
    return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

void Solve()
{
    int n;
    cin >> n;
    map<int, set<pi>> points_by_color;
    set<vector<long long>> alls;
    forn
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (points_by_color.find(c) == points_by_color.end())
        {
            points_by_color[c] = set<pi>();
        }
        points_by_color[c].insert({a, b});
        pi pt = {a, b};
        if (*points_by_color[c].begin() != pt && *points_by_color[c].rbegin() != pt)
        {
            points_by_color[c].erase(pt);
        }
    }
    for (auto x : points_by_color)
    {
        for (auto y : x.second)
        {
            alls.insert({y.first, y.second, x.first});
        }
    }
    long long best = 0;
    vector<vector<long long>> candidates;
    for (int i = 0; i < 3; i++)
    {
        if (alls.sz > 0)
        {
            candidates.pb(*alls.begin());
            alls.erase(alls.begin());
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (alls.sz > 0)
        {
            candidates.pb(*alls.rbegin());
            auto pt = *alls.rbegin();
            alls.erase(pt);
        }
    }
    for (int l = 0; l < candidates.sz; l++)
    {
        for (int r = l + 1; r < candidates.sz; r++)
        {
            if (candidates[l][2] != candidates[r][2])
            {
                best = max(best, d({candidates[l][0], candidates[l][1]}, {candidates[r][0], candidates[r][1]}));
            }
        }
    }
    cout << best << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}