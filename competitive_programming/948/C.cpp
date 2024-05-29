// Problem: C. Nikita and LCM
// Contest: Codeforces - Codeforces Round 948 (Div. 2)
// URL: https://codeforces.com/contest/1977/problem/C
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
#define pi pair<long long, long long>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

long long mcd(long long a, long long b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, a % b);
    }
}

void Solve()
{
    int n;
    cin >> n;
    long long a[n];
    forn
    {
        cin >> a[i];
    }
    set<long long> vals;
    forn
    {
        vals.insert(a[i]);
    }
    set<pi> mcms;
    mcms.insert({1, 0});
    long long best = 0;
    forn
    {
        int flag = 0;
        set<pi> up;
        for (auto x : mcms)
        {
            long long upd = x.first * a[i] / mcd(a[i], x.first);
            if (upd > 1e9)
            {
                cout << n << endl;
                return;
            }
            up.insert({upd, x.second + 1});
        }
        for (auto x : up)
        {
            auto cl = mcms.lower_bound({x.first, -1});
            if (cl != mcms.end() && (*cl).first == x.first)
            {
                mcms.erase(cl);
            }
            mcms.insert(x);
        }
    }
    for (auto x : mcms)
    {
        if (vals.find(x.first) == vals.end())
        {
            best = max(best, x.second);
        }
    }
    cout << best << endl;
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