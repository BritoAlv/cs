// Problem: A. Glory Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/A
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
    int n;
    cin >> n;
    vector<int> flag(n);
    forn
    {
        cin >> flag[i];
    }
    vector<int> a;
    vector<int> b;
    forn
    {
        int x;
        cin >> x;
        if (flag[i])
        {
            a.pb(x);
        }
        else
        {
            b.pb(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pi> result;
    if (a.sz != b.sz)
    {
        if (a.sz < b.sz)
        {
            for (int i = 0; i < b.sz - a.sz; i++)
            {
                result.pb({b[i], 0});
            }
            for (int i = b.sz - a.sz; i < b.sz; i++)
            {
                result.pb({a[i - (b.sz - a.sz)], 1});
                result.pb({b[i], 0});
            }
        }
        else
        {
            for (int i = 0; i < a.sz - b.sz; i++)
            {
                result.pb({a[i], 0});
            }
            for (int i = a.sz - b.sz; i < a.sz; i++)
            {
                result.pb({b[i - (a.sz - b.sz)], 1});
                result.pb({a[i], 0});
            }
        }
    }
    else
    {
        if (a.sz > 0)
        {
            if (a[0] < b[0])
            {
                for (int i = 0; i < a.sz; i++)
                {
                    result.pb({a[i], 1});
                    result.pb({b[i], 0});
                }
            }
            else
            {
                for (int i = 0; i < a.sz; i++)
                {
                    result.pb({b[i], 1});
                    result.pb({a[i], 0});
                }
            }
        }
    }
    ull sum = 0;
    for (int i = 0; i < result.sz; i++)
    {
        int prev = 1;
        if (i > 0 && result[i].second != result[i - 1].second)
        {
            prev++;
        }
        sum += prev * result[i].first;
    }
    cout << sum << endl;
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