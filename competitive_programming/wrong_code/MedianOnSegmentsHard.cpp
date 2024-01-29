// Problem: E1. Median on Segments (Permutations Edition)
// Contest: Codeforces - Codeforces Round 496 (Div. 3)
// URL: https://codeforces.com/contest/1005/problem/E1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
using namespace std;

void Solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    forn
    {
        cin >> a[i];
    }
    vector<int> m_positions;
    int last_seen = -1;
    int m_assigned_r[n];
    int m_assigned_l[n];
    forn
    {
        m_assigned_l[i] = -1;
    }
    forn
    {
        if (a[i] != m)
        {
        }
        else
        {
            last_seen++;
            for (int j = i; j >= (m_positions.size() == 0 ? 0 : m_positions.back() + 1); j--)
            {
                m_assigned_l[j] = last_seen;
            }
            m_positions.pb(i);
        }
        m_assigned_r[i] = last_seen;
    }
    vector<int> less_m(n, 0);
    vector<int> greater_m(n, 0);
    vector<int> dif_l(n, 0);
    vector<int> dif_r(n, 0);
    for (int i = 0; i < n; i++)
    {
        less_m[i] = (i > 0 ? less_m[i - 1] : 0) + (a[i] < m);
    }
    for (int i = 0; i < n; i++)
    {
        greater_m[i] = (i > 0 ? greater_m[i - 1] : 0) + (a[i] > m);
    }
    for (int i = 0; i < n; i++)
    {
        dif_r[i] = greater_m[i] - less_m[i];
    }
    for (int i = 0; i < n; i++)
    {
        dif_l[i] = (i > 0 ? greater_m[i - 1] : 0) - (i > 0 ? less_m[i - 1] : 0);
    }
    map<int, vector<int>> count;
    for (int i = 0; i < n; i++)
    {
        if (m_assigned_l[i] >= 0)
        {
            if (count.find(dif_l[i]) == count.end())
            {
                vector<int> v(last_seen + 1, 0);
                count.insert({dif_l[i], v});
            }
            count[dif_l[i]][m_assigned_l[i]]++;
        }
    }
    for (auto &x : count)
    {
        for (int i = 1; i < x.second.size(); i++)
        {
            x.second[i] = x.second[i] + x.second[i - 1];
        }
    }
    ull ans = 0;
    for (int r = 0; r < n; r++)
    {
        // count how many values in [0, l]:
        // its dif_l is equal to dif_r or dif_r - 1
        int assigned = m_assigned_r[r];
        if (assigned >= 0)
        {
            if (count.find(dif_r[r]) != count.end())
            {
                ans += count[dif_r[r]][assigned];
            }
            if (count.find(dif_r[r] - 1) != count.end())
            {
                ans += count[dif_r[r] - 1][assigned];
            }
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    int test_cases = 1;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}