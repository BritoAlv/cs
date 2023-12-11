// Problem: D1. Set To Max (Easy Version)
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/D1
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

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    map<int, vector<int>> vals;
    forn
    {
        cin >> a[i];
    }
    forn
    {
        cin >> b[i];
        if (vals.find(b[i]) == vals.end())
        {
            vals[b[i]] = vector<int>();
        }
        vals[b[i]].pb(i);
    }
    int works = 1;
    auto it = vals.end();
    while (it != vals.begin())
    {
        it--;
        vector<int> slice = (*it).second;
        int value = (*it).first;
        vector<pair<int, int>> segments;
        for (int i = 0; i < slice.size(); i++)
        {
            int start = i;
            int end = i;
            while (end + 1 < slice.size() && slice[end + 1] == slice[end] + 1)
            {
                end++;
            }
            segments.pb({slice[start], slice[end]});
            i = end;
        }
        for (auto x : segments)
        {
            int start = x.first;
            int end = x.second;
            int maxx = a[start];
            while (start - 1 >= 0 && b[start - 1] >= value && a[start - 1] <= value)
            {
                start--;
            }
            while (end + 1 < n && b[end + 1] >= value && a[end + 1] <= value)
            {
                end++;
            }
            for (int j = start; j <= end; j++)
            {
                maxx = max(maxx, a[j]);
            }

            if (maxx != value)
            {
                works = 0;
                break;
            }
        }
    }
    cout << (works ? "YES" : "NO") << endl;
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
